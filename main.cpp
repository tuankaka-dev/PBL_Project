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

    // hàm tạo
    product(string name, double price, string type, int amount)
    {
        this->name = name;
        this->price = price;
        this->type = type;
        this->amount = amount;
    };
};

int main()
{
    // check tài khoản admin từ file

    fstream check_admin;
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
            break;
        case 2:
            cout << "Ban da chon 2" << endl;
            break;
        case 3:
            cout << "Ban da chon 3" << endl;
            break;
        case 4:
            cout << "Ban da chon 4" << endl;
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
