#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include"person.h"
#include"Thisinh.h"
#include"node.h"
using namespace std;

void Form()
{
    cout << "+";
    for (int i = 0; i < 153; i++)
        cout << "-";
    cout << "+" << endl;
    cout << "|" << setw(15) << "Tên" << setw(20) << "|";
    cout << setw(10) << "CCCD" << setw(10) << "|";
    cout << setw(5) << "GT" << setw(3) << "|";
    cout << setw(15) << "Ngày Sinh" << setw(5) << "|";
    cout << setw(17) << "Địa Chỉ" << setw(8) << "|";
    cout << setw(8) << "SBD" << setw(8) << "|";
    cout << setw(8) << "Toán" << setw(3) << "|";
    cout << setw(6) << "Lý" << setw(3) << "|";
    cout << setw(7) << "Hóa" << setw(3) << "|";
    cout << setw(9) << "Tổng" << setw(3) << "|" << endl;
}
class LinkedList
{
   
public:
 node *head;

    LinkedList()
    {
        head = NULL;
    }
    void insert(ThiSinh sv)
    {
        node *newNode = new node(sv);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    node *search(string sbd, string name)
    {
        node *temp = head;
        while (temp->data.getsbd() != sbd)
            temp = temp->next;
        if (temp->data.getname() == name)
            return temp;
        else
            return NULL;
    }
    bool Delete(string sbd, string name)
    {
        node *p = search(sbd, name);
        if (p != NULL)
        {
            node *pre;
            node *temp = head;
            while (p->data.getsbd() != temp->data.getsbd())
            {
                pre = temp;
                temp = temp->next;
            }
            pre->next = temp->next;
            delete (temp);
            return true;
        }
        else
            return false;
    }
    void xuat()
    {
    node *temp = head;
        while (temp != NULL)
        {
            temp->data.display();
            temp = temp->next;
        }
    cout << "|";
     for (int i = 0; i < 153; i++)
        cout << "-";
    cout << "|" << endl;
    }
    void docfile();
    void ghifile();
    bool testempty()
    {
        if (head == NULL)
        {
            cout << "Danh sách rỗng.";
            return true;
        }
        else
        {
            return false;
        }
    }
    void sapxepdiem();
    void searchinf()
    {
        docfile();
        string c;
        int lc;
        do
        {
                      system("cls");
            cout << setw(105) << "CÁC THÔNG TIN CẦN TÌM" << endl;
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
            cin >> lc;
            while (lc < 0 || lc > 6)
            {
                fflush(stdin);
                cout << "Lựa chọn của bạn là không hợp lệ!!! \n Hãy nhập lại: ";
                cin >> lc;
            }
            switch (lc)
            {
           case 1:
            {
                fflush(stdin);
                string name;
                node *p = head;
                cout << "nhập tên bạn muốn hiển thị: ";
                getline(cin, name);
                Form();
                while (p != nullptr)
                {
                    if (p->data.getname().find(name) != string::npos)
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                cout << "|";
                for (int i = 0; i < 153; i++)
                    cout << "-";
                cout << "|" << endl;
                system("pause");
                break;
            }
            case 2:
            {
                fflush(stdin);
                string address;
                node *p = head;
                cout << "nhập địa chỉ bạn muốn hiển thị: ";
                getline(cin, address);
                Form();
                while (p != nullptr)
                {
                    if (p->data.getaddress().find(address) != string::npos)
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                cout << "|";
                for (int i = 0; i < 153; i++)
                    cout << "-";
                cout << "|" << endl;
                system("pause");
                break;
            }
            case 3:
            {
                fflush(stdin);
                string cccd;
                node *p = head;
                cout << "nhập những số trong cccd bạn muốn hiển thị: ";
                getline(cin, cccd);
                Form();
                while (p != nullptr)
                {
                    if (p->data.getcccd().find(cccd) != string::npos)
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                cout << "|";
                for (int i = 0; i < 153; i++)
                    cout << "-";
                cout << "|" << endl;
                system("pause");
                break;
            }
            case 4:
            {
                fflush(stdin);
                string sbd;
                node *p = head;
                cout << "nhập những số có trong số báo danh mà bạn muốn hiển thị: ";
                getline(cin, sbd);
                Form();
                while (p != nullptr)
                {
                    if (p->data.getsbd().find(sbd) != string::npos)
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                cout << "|";
                for (int i = 0; i < 153; i++)
                    cout << "-";
                cout << "|" << endl;
                system("pause");
                break;
            }
            case 5:
            {
                fflush(stdin);
                int ns;
                node *p = head;
                cout << "nhập năm sinh bạn muốn hiển thị: ";
                cin >> ns;
                Form();
                while (p != nullptr)
                {
                    if (p->data.getdate().year == ns)
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                cout << "|";
                for (int i = 0; i < 153; i++)
                    cout << "-";
                cout << "|" << endl;
                system("pause");
                break;
            }
            case 6:
            {
                cin.ignore();
                string gt;
                node *p = head;
                cout << "Bạn muốn hiển thị giới tính nào (nam/nu): ";
                getline(cin, gt);
                Form();
                for (int i = 0; i < gt.length(); i++)
                {
                    gt[i] = tolower(gt[i]);
                }
                while (p != nullptr)
                {
                    if ((gt == "nam" && p->data.getgt() == 0) || (gt == "nu" && p->data.getgt() == 1))
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                cout << "|";
                for (int i = 0; i < 153; i++)
                    cout << "-";
                cout << "|" << endl;
                system("pause");
                break;
            }
            }
            cout << "bạn có muốn tìm kiếm thông tin tiếp hay không? (y/n) ";
            cin >> c;
        } while (c == "y" || c == "Y");
    }
};

void LinkedList::docfile()
{
    ThiSinh ts;
    ifstream inputFile;
    inputFile.open("dsthisinh.txt", ios::in);
    if (inputFile.is_open())
    {
        string line;
        size_t pos;
        while (getline(inputFile, line))
        {
            pos = line.find(",");
            ts.setname(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setcccd(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            try {
                ts.setgt(stoi(line.substr(0, pos)));
            }
            catch (const invalid_argument& e) {
                cerr << "Lỗi: " << e.what() << " - Giá trị không hợp lệ: " << line.substr(0, pos) << std::endl;
                // Xử lý lỗi ở đây (ví dụ: gán giá trị mặc định)
                ts.setgt(0); 
            }
            line.erase(0, pos + 1);

            Date d;
            pos = line.find("/");
            d.day = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);
            pos = line.find("/");
            d.month = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);
            pos = line.find(",");
            d.year = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);
            ts.setdate(d);

            pos = line.find(",");
            ts.setaddress(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setsbd(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setto(stof(line.substr(0, pos)));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setli(stof(line.substr(0, pos)));
            line.erase(0, pos + 1);

            ts.sethoa(stof(line));
            insert(ts);
        }

        inputFile.close();
    }
    else {
        cout << "Không thể mở file." << endl;
    }
}
void LinkedList::sapxepdiem()
{
    if (head == NULL)
    {
        cout << "Danh sách rỗng.";
        return;
    }

    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    bool swapped;
    node *ptr1;
    node *lptr = NULL;

    // Lặp lại quá trình sắp xếp cho đến khi không có cặp phần tử nào được tráo đổi
    for (int i = 0; i < count - 1; i++)
    {
        swapped = false;
        ptr1 = head;

        // Lặp qua tất cả các phần tử và so sánh điểm của chúng
        for (int j = 0; j < count - i - 1; j++)
        {
            if (ptr1->data.getsum() < ptr1->next->data.getsum())
            {
                // Hoán đổi nội dung giữa hai phần tử
                ThiSinh temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }

        // Nếu không có phần tử nào được tráo đổi, thì danh sách đã được sắp xếp
        if (swapped == false)
            break;
    }
}

void LinkedList::ghifile(){
    ofstream outputFile;
    outputFile.open("dsthisinh.txt", ios::out);
    if (outputFile.is_open())
    {
        node* current = head; 
        while (current != NULL)
        {
            outputFile << current->data.getname() << ", " << current->data.getcccd() << ", " << current->data.getgt() << ", "
                       << current->data.getdate().day << "/" << current->data.getdate().month << "/" << current->data.getdate().year
                       << ", " << current->data.getaddress() << ", " << current->data.getsbd() << ", " << current->data.getto()
                       << ", " << current->data.getli() << ", " << current->data.gethoa() << endl;
            
            current = current->next; 
        }
        outputFile.close();
    }
    else {
        cout << "Không thể mở file." << endl;
    }
}
