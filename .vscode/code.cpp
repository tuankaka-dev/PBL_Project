#include <bits/stdc++.h>
using namespace std;
// lớp sản phẩm
class product
{
public:
    string name;
    double price;
    string type;
    int amount;
    // ham tao mac dinh
    product()
    {
        name = "#";
        price = 0;
        type = "#";
        amount = 0;
    }
    // hàm tạo
    product(string name, double price, string type, int amount)
    {

        // mở file sản phẩm
        fstream product_list("product_list.txt", ios::out | ios::app);
        if (product_list.is_open())
        {
            // ghi thông tin sản phẩm vào file
            product_list << left
                         << setw(10) << name << setw(10) << price << setw(10) << setw(10) << type << setw(10) << amount << endl;
        }
        else
        {
            cout << "Khong the mo file" << endl;
        }
        product_list.close();
    };
    // ham them san pham
    void add_product()
    {
        // nhap thông tin sản phẩm
        cin.ignore();
        cout << "nhap san pham" << endl;
        getline(cin, name);
        cout << "nhap gia san pham" << endl;
        cin >> price;
        cout << "nhap loai san pham" << endl;
        cin >> type;
        cout << "nhap so luong san pham" << endl;
        cin >> amount;
        product(name, price, type, amount);
        cout << "Da them san pham thanh cong" << endl;
    }
};

// ham hien thi san pham
void show_product()
{

    cout << "========================================================" << endl;
    cout << "=                   CUA HANG TRANG SUC H&T             =" << endl;
    cout << "========================================================" << endl;
    cout << left
         << setw(10) << "STT" << setw(10) << "Ten" << setw(10) << "Gia" << setw(10) << "Loai" << setw(10) << "So luong" << endl;
    // mở file sản phẩm
    fstream product_list("product_list.txt", ios::in);
    if (product_list.is_open())
    {
        string line;
        getline(product_list, line);
        cout << 1 << "        " << line << endl;
        int stt = 2;
        while (getline(product_list, line))
        {
            cout << stt << "        " << line << endl;
            stt++;
        }
    }
    else
    {
        cout << "Khong tim thay file" << endl;
    }
    product_list.close();
}

void delete_product(int delete_line)
{

    ifstream product_list("product_list.txt");
    ofstream temp("temp.txt");
    if (product_list.is_open())
    {
        string line;
        int count = 0;
        while (getline(product_list, line))
        {
            count++;
            if (count != delete_line)
            {
                temp << line << endl;
            }
        }

        product_list.close(); //
        temp.close();         //
        remove("product_list.txt");
        rename("temp.txt", "product_list.txt");
      
        cout << "Da xoa san pham STT " << delete_line << " thanh cong" << endl;
        
    }
    else
    {
        cout << "Khong the mo file" << endl;
    }
}
void menu_option()
{
    
    product p1;
    int choice;
    do
    {
        // đăng nhập thành công hiện ra ADMIN PANEL
        cout << "========================================================" << endl;
        cout << "                        ADMIN PANEL                     " << endl;
        cout << "========================================================" << endl;
        cout << left
             << setw(10) << "1. Them san pham" << endl
             << setw(10) << "2. Xoa san pham" << endl
             << setw(10) << "3. Danh sach san pham" << endl
             << setw(10) << "0. Thoat" << endl;
        cout << "--------------------------------------------------------" << endl;
        // Nhập lựa chọn từ người dùng

        cout << "Nhap mot lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            p1.add_product();
            show_product();
            break;
        case 2:
            int delete_line;
            show_product();
            cout << "Nhap STT san pham can xoa" << endl;
            cin >> delete_line;
            delete_product(delete_line);
            show_product();
            break;
        case 3:
            show_product();
            break;
        case 0:
            cout << "Thoat" << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }

    } while (choice != 0);

}

int main()
{

    // check tài khoản admin từ file
    fstream check_admin, product_list;
    check_admin.open("check_admin.txt", ios::in);
    if (check_admin.is_open())
    {
        string id, pass, enter_id, enter_pass;
        getline(check_admin, id);
        getline(check_admin, pass);
        do
        {
            cout << "========================================================" << endl;
            cout << "                    DANG NHAP ADMIN                     " << endl;
            cout << "========================================================" << endl;
            cout << left << setw(20) << "Nhap tai khoan: ";
            cin >> enter_id;
            cout << left << setw(20) << "Nhap mat khau: ";
            cin >> enter_pass;

            if (enter_id == id && enter_pass == pass)
            {
                cout << "Dang nhap thanh cong, xin chao " << enter_id << "!" << endl;
            }
            else
            {
                cout << "Sai tai khoan hoac mat khau. Vui long thu lai!" << endl;
            }
        } while (enter_id != id || enter_pass != pass);
        // hiện ra menu tùy chọn
        menu_option();
    }
    else
    {
        cout << "Khong tim thay file" << endl;
    }
    check_admin.close();
}