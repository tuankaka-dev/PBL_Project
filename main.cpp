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
    fstream product_list;
    // ham tao mac dinh
    product()
    {
        name = " ";
        price = 0;
        type = " ";
        amount = 0;
    }
    // hàm tạo
    product(string name, double price, string type, int amount)
    {
        this->name = name;
        this->price = price;
        this->type = type;
        this->amount = amount;
        // ghi thông tin sản phẩm vào file
        product_list.open("product_list.txt", ios::out | ios::app);
        if (product_list.is_open())
        {
            product_list << left 
                         << setw(10) << name << setw(10)  << price << setw(10) << setw(10) << type << setw(10) << amount << endl;
        }
        else
        {
            cout << "Khong the mo file" << endl;
        }
    };
    // ham them san pham
    void add_product()
    {
        // nhap thông tin sản phẩm
        cout << "nhap san pham" << endl;
        cin >> name;
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
void show_product(fstream &product_list)
{
    //tao dao dien 
    cout << "========================================================" << endl;
    cout << "=                   CUA HANG TRANG SUC H&T             =" << endl;
    cout << "========================================================" << endl;
    cout << left
         << setw(10) << "Ten" << setw(10) << "Gia" << setw(10) << "Loai" << setw(10) << "So luong" << endl;
    // mở file sản phẩm
    product_list.open("product_list.txt", ios::in);
    if (product_list.is_open())
    {
        string line;
        getline(product_list, line);
        cout << line << endl;
        while (getline(product_list, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "Khong the mo file" << endl;
    }
    product_list.close();
}
int main()
{
    // tạo đối tượng sản phẩm
    product p1;
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

        // đăng nhập thành công hiện ra ADMIN PANEL
        cout << "========================================================" << endl;
        cout << "                        ADMIN PANEL                     " << endl;
        cout << "========================================================" << endl;
        cout << left
             << setw(10) << "1. Them san pham"      << endl
             << setw(10) << "2. Chinh sua san pham" << endl
             << setw(10) << "3. Xoa san pham"       << endl
             << setw(10) << "4. Danh sach san pham" << endl
             << setw(10) << "0. Thoat"              << endl;
        cout << "--------------------------------------------------------" << endl;
        // Nhập lựa chọn từ người dùng
        
        int choice;
        do{
        cout << "Nhap mot lua chon: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            cout << "Ban da chon 1" << endl;
            p1.add_product();
            break;
        case 2:
            cout << "Ban da chon 2" << endl;
            break;
        case 3:
            cout << "Ban da chon 3" << endl;
            break;
        case 4:
            cout << "Ban da chon 4" << endl;
            show_product(product_list);
            break;
        case 0:
            cout<<  "Thoat"         << endl;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    
        }while (choice < 0 || choice > 4);

}
else
{
    cout << "Khong tim thay file" << endl;
}
check_admin.close();
}
