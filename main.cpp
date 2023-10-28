#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <stdexcept> 
#include"person.h"
#include"Thisinh.h"
#include"linklist.h"
using namespace std;

string  capitalizeFirstLetter(string &str) {
    int len = str.length();
    if (len == 0 || str[0] == ' ') {
        return str;
    }
    str[0] = toupper(str[0]);
    for (int i = 1; i < len; i++) {
        if (str[i] == ' ' && isalpha(str[i + 1])) {
            str[i + 1] = toupper(str[i + 1]);
        }
    }
    return str;
}
 
void signin(string &name, string &sbd)
{
    fflush(stdin);
    cout << "Tên: ";
    getline(cin, name);
    name = capitalizeFirstLetter(name);
    cout << "sbd: ";
    getline(cin, sbd);
}
void editinfor(LinkedList &ds, string sbd, string name)
{
    ds.docfile();
    node *p = ds.search(sbd, name);
    string New;
    int d;
    string c;
    Date date;
    int luachon;
    do
    {
        system("cls");
        cout << "\n\n\t CÁC THÔNG TIN CẦN SỬA\n\n\t+";
            cout << setw(75) << "+";
            for (int i = 1; i <= 30; ++i)
                cout << "-";
            cout << "+" << endl;
            cout << setw(107) << "|   1. Tên                     |" << endl;
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(111) << "|   2. Địa chỉ                 |" << endl;
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(107) << "|   3. CCCD                    |\n";
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(107) << "|   4. SBD                     |\n";
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(108) << "|   5. Năm sinh                |\n";
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(109) << "|   6. Giới tính               |" << endl;
            cout << setw(75) << "+";
            for (int i = 1; i <= 30; ++i)
                cout << "-";
            cout << "+" << endl;
            cout << endl;
            cout << setw(80) << "Mời nhập lựa chọn :";
            cin >> luachon;
        while (luachon < 0 || luachon > 6)
        {
            fflush(stdin);
            cout << "Lựa chọn của bạn là không hợp lệ!!! \n Hãy nhập lại: ";
            cin >> luachon;
        }
        switch (luachon)
        {
        case 1:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                cout << "Nhập lại tên: ";
                cin.ignore();
                getline(cin, New);
                p->data.setname(New);
            }
            break;
        case 2:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                cout << "Nhập lại ngày/tháng/năm sinh: " << endl;
                cout << "Nhập ngày: ";
                cin >> date.day;
                cout << "Nhập tháng: ";
                cin >> date.month;
                cout << "Nhập năm: ";
                cin >> date.year;
                p->data.setdate(date);
            }
            break;
        case 3:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                string newAddress;
                cout << "Nhập địa chỉ mới: ";
                cin.ignore();
                getline(cin, newAddress);
                p->data.setaddress(newAddress);
            }
            break;
        case 4:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                string newCCCD;
                cout << "Nhập số CCCD mới: ";
                cin.ignore();
                getline(cin, newCCCD);
                p->data.setcccd(newCCCD);
            }
            break;
        case 5:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                int newgt;
                cout << "Nhập giới tính mới: (0: Nam, 1: Nữ) ";
                cin >> newgt;
                p->data.setgt(newgt);
            }
            break;
        case 6:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                float newMath, newPhysics, newChemistry;
                cout << "Nhập điểm toán mới: ";
                cin >> newMath;
                cout << "Nhập điểm lý mới: ";
                cin >> newPhysics;
                cout << "Nhập điểm hóa mới: ";
                cin >> newChemistry;
                p->data.setto(newMath);
                p->data.setli(newPhysics);
                p->data.sethoa(newChemistry);
            }
            break;
        }
        cout << "bạn có muốn tìm kiếm thông tin tiếp hay không?(y/n)";
        cin >> c;
    } while (c == "y" || c == "Y");
}
void TextColor(int x)//X là mã màu
{
     HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
int main()
{
    LinkedList danhsach;
    ThiSinh ts;
    string sbd;
    string name;
    int option;
    danhsach.docfile();
    do
    {
         system("cls");
        TextColor(4);
        cout << setw(135) << "~- QUẢN LÝ ĐIỂM THI CỦA CÁC THÍ SINH VÀO MỘT TRƯỜNG ĐẠI HỌC -~" << endl;
        TextColor(10);
        cout << setw(27);
        for (int i = 1; i <= 125; ++i)
            cout << "-";
        cout << setw(124) << "DANH SÁCH CÁC THAO TÁC";
        cout << setw(140) << "+";
        for (int i = 1; i <= 50; ++i)
            cout << "-";
        cout << "+" << endl;
        cout << setw(114) << "|   1. Thêm 1 thí sinh vào danh sách.              |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(116) << "|   2. Xoá 1 thí sinh khỏi danh sách.              |\n ";
        cout << setw(57) << "|" << setw(51) << "|" << endl;
        cout << setw(114) << "|   3. Sửa thông tin 1 thí sinh.                   |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(118) << "|   4. Xuất thông tin của một thí sinh.            |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(118) << "|   5. Tìm kiếm các thông tin của thí sinh.        |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        // cout << setw(121) << "|   6. Danh sách các thí sinh đậu đại học.         |\n";
        // cout << setw(58) << "|" << setw(51) << "|" << endl;
        // cout << setw(117) << "|   7. Danh sách các ngành đào tạo.                |\n";
        // cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(118) << "|   8. Sắp xếp danh sách theo điểm.                |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(111) << "|   0. Thoát.                                      |\n";
        cout << setw(58) << "|" << setw(51) << "|" << endl;
        cout << setw(58) << "+";
        for (int i = 1; i <= 50; ++i)
            cout << "-";
        cout << "+" << endl;
        cout << endl;
        TextColor(7);
        cout << setw(80) << "Mời nhập lựa chọn : ";
        cin >> option;
        while (option < 0 || option > 8)
        {
            fflush(stdin);
            cout << "Lựa chọn của bạn là không hợp lệ!!! \n Hãy nhập lại: ";
            cin >> option;
        }
        switch (option)
        {
        case 0:
            break;
        case 1:
        {
            ts.input();
            danhsach.insert(ts);
            danhsach.ghifile();
            cout << "Đã thêm thành công\n";
            system("pause");
            break;
        }
        case 2:
        {
            for (int i = 0; i < 50; i++)
                cout << "-";
            cout << endl;
            cout << "Bạn muốn xóa thông tin của ai:" << endl;
             signin(name, sbd);
            if (danhsach.search(sbd, name) != NULL)
            {
                if (danhsach.Delete(sbd, name) == true)
                    cout << "Đã xóa thành công\n";
                else
                    cout << "Không xóa được thông tin này" << endl;
            }
            else
                cout << "Không tìm thấy thông tin cần xóa" << endl;
            system("pause");
            break;
        }
        case 3:
        {
            for (int i = 0; i < 50; i++)
                cout << "-";
            cout << endl;
            cout << "Bạn muốn sửa thông tin của ai:" << endl;
            signin(name, sbd);
            if (danhsach.search(sbd, name) != NULL)
            {
                editinfor(danhsach, sbd, name);
                cout << "Đã cập nhật thông tin\n";
            }
            else
                cout << "Không tìm thấy thông tin cần sửa" << endl;
            system("pause");
            break;
        }
        case 4:
        {
            Form();
            danhsach.xuat();
            system("pause");
            break;
        }
        case 5:
        {
            for (int i = 0; i < 50; i++)
                cout << "-";
            cout << endl;
            cout << "Bạn muốn tìm kiếm thông qua thông tin gì?" << endl;
            danhsach.searchinf();
            system("pause");
            break;
        }
        case 6:
        {
           
            system("pause");
            break;
        }
        case 7:
        {
            system("pause");
            break;
        }
        case 8:
        {
            danhsach.sapxepdiem();
            danhsach.xuat();
            system("pause");
            break;
        }
        }
    } while (option != false);
}
