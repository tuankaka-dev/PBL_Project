#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void clrscr()
{
    system("cls");
}
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// lớp sản phẩm
class product
{
private:
    string name;
    double price;
    string type;
    int amount;
    string check_price;
    string check_amount;
public:
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
        do
        {
            cin >> check_price;
            if (check(check_price) == false)
            {
                cout << "Gia khong hop le, vui long nhap lai" << endl;
            }
        } while (check(check_price) == false);
        price = stof(check_price);
        cout << "nhap loai san pham" << endl;
        cin >> type;
        cout << "nhap so luong san pham" << endl;
        do
        {
            cin >> check_amount;
            if (check(check_amount,1) == false)
            {
                cout << "So luong khong hop le, vui long nhap lai" << endl;
            }
        } while (check(check_amount,1) == false);
        amount = stoi(check_amount);
        product(name, price, type, amount);
        cout << "Da them san pham thanh cong" << endl;
    }
    bool check(string check_price);
    bool check(string check_amount,int);
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
// hàm xóa sản phẩm
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
    }
    else
    {
        setColor(14);
        cout << "Khong the mo file" << endl;
        setColor(7);
    }
}

void menu_option()
{

    product p1;
    int choice;
    do
    {

        // đăng nhập thành công hiện ra ADMIN PANEL
        setColor(14);
        cout << "========================================================" << endl;
        cout << "                     ADMIN PANEL                        " << endl;
        cout << "========================================================" << endl;
        setColor(7);
        cout << left
             << setw(10) << "1. Them san pham" << endl
             << setw(10) << "2. Xoa san pham" << endl
             << setw(10) << "3. Danh sach san pham" << endl
             << setw(10) << "0. Thoat" << endl;
        cout << "--------------------------------------------------------" << endl;
        // Nhập lựa chọn từ người dùng

        setColor(14);
        cout << "Nhap mot lua chon: ";
        setColor(7);
        cin >> choice;
        switch (choice)
        {
        case 1:
            clrscr();
            p1.add_product();
            clrscr();
            show_product();

            break;
        case 2:
            clrscr();
            int delete_line;
            show_product();
            setColor(2);
            cout << "Nhap STT san pham can xoa" << endl;
            setColor(7);
            cin >> delete_line;
            delete_product(delete_line);
            show_product();
            setColor(2);
            cout << "Da xoa san pham STT " << delete_line << " thanh cong" << endl;
            setColor(7);

            break;
        case 3:
            clrscr();
            show_product();

            break;
        case 0:
            setColor(2);
            cout << "Thoat" << endl;
            setColor(7);
            break;
        default:
            setColor(2);
            cout << "Lua chon khong hop le!" << endl;
            setColor(7);
        }

    } while (choice != 0);
}
// kiểm tra giá sản phẩm
bool product::check(string check_price)
{
    int count = 0;
    for (char c : check_price)
    {
        if ((c < '0' || c > '9') && c != '.')
        {
            return false;
            break;
        }
        if (c == '.')
        {
            count++;
            if (count > 1)
            {
                return false;
                break;
            }
        }
    }
    return true;
}
// kiểm tra số lượng sản phẩm
bool product::check(string check_amount,int)
{
    for (char c : check_amount)
    {
        if (c < '0' || c > '9')
        {
            return false;
            break;
        }
    }
    return true;
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
            setColor(14);
            cout << "========================================================" << endl;
            cout << "                    DANG NHAP ADMIN                     " << endl;
            cout << "========================================================" << endl;
            setColor(7);
            cout << left << setw(20) << "Nhap tai khoan: ";
            cin >> enter_id;
            cout << left << setw(20) << "Nhap mat khau: ";
            cin >> enter_pass;
            clrscr();
            if (enter_id == id && enter_pass == pass)
            {
                setColor(2);
                cout << "Dang nhap thanh cong, xin chao " << enter_id << "!" << endl;
                setColor(7);
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
        setColor(2);
        cout << "Khong tim thay file" << endl;
        setColor(7);
    }
    check_admin.close();
}
