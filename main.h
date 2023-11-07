#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include"linklist.h"
#include"Nganh.h"
using namespace std;


typedef bool (*CompareFunc)(ThiSinh &, string &);

bool CompareByName(ThiSinh &ts, string &name)
{
    return (ts.name.find(name) != string::npos);
}

bool CompareByAddress(ThiSinh &ts,string &address)
{
    return (ts.address.find(address) != string::npos);
}

bool CompareByCCCD(ThiSinh &ts,string &cccd)
{
    return (ts.cccd.find(cccd) != string::npos);
}

bool CompareBySBD(ThiSinh &ts,string &sbd)
{
    return (ts.sbd.find(sbd) != string::npos);
}

bool CompareByYear(ThiSinh &ts,string &yearStr)
{
    int year = stoi(yearStr);
    return (ts.date.year == year);
}

bool CompareByGender(ThiSinh &ts,  string &gender)
{
    
    return (ts.gt.find(gender) != string::npos);
}

void DisplayFilteredData(LinkedList &list, const string &message, CompareFunc compareFunc, string compareValue)
{
    fflush(stdin);
    node *p = list.getHead();
    cout << message + ": ";
    getline(cin, compareValue);
    compareValue = capitalizeFirstLetter(compareValue);
    Form();
    while (p != NULL)
    {
        if (compareFunc(p->data, compareValue))
        {
            p->data.display();
        }
        p = p->next;
    }
    cout << "|";
    for (int i = 0; i < 153; i++)
    {
        cout << "-";
    }
    cout << "|" << endl;
    system("pause");
}

void search_info(LinkedList &list)
{
    string value;
    string c;
    int lc;
    do
    {
          system("cls");
           SetColor1(7,2);
         gotoXY(62,4);
           cout << "CAC THONG TTN CAN TIM" ;
        Form1();
        gotoXY(62,13);
        cout << "Moi nhap lua chon :";
        cin >> lc;
        while (lc < 0 || lc > 6)
        {
            fflush(stdin);
            cout << "Lua chon cua ban khong hop le!!! \n Hay nhap lai: ";
            cin >> lc;
        }
        switch (lc)
        {
        case 1:
            DisplayFilteredData(list, "Nhap ten ban muon hien thi?", CompareByName, value);
            break;
        case 2:
            DisplayFilteredData(list, "Nhap dia chi ban muon hien thi?", CompareByAddress, value);
            break;
        case 3:
            DisplayFilteredData(list, "Nhap so can cuoc cong dan ban muon hien thi?", CompareByCCCD, value);
            break;
        case 4:
            DisplayFilteredData(list, "Nhap so bao danh ma ban muon hien thi?", CompareBySBD, value);
            break;
        case 5:
        {
            string yearString;
            DisplayFilteredData(list, "Nhap nam sinh ban muon hien thi?", CompareByYear, value);
            break;
        }
        case 6:
            DisplayFilteredData(list, "Ban muon hien thi gioi tinh nao? (Nam/Nu)", CompareByGender, value);
            break;
        }
        cout << "Ban co muon tim tiep hay khong? (y/n) ";
        cin >> c;
    } while (c == "y" || c == "Y");
}


void edit_infor(LinkedList &ds, string sbd, string name)
{
    node *p = ds.search(sbd, name);
    string New;
    int d;
    string c;
    Date date;
    int luachon;
    do
    {
         system("cls");
            SetColor1(7,2);
         gotoXY(62,4);
            cout  << "CAC THONG TIN CAN SUA" << endl;
        Form1();
        gotoXY(62,12);
        cout << "7. Diem";
        gotoXY(62,14);
            cout << "Moi nhap lua chon :";
            cin >> luachon;
        while (luachon < 0 || luachon > 8)
        {
            fflush(stdin);
            gotoXY(62,16);
            cout << "Lua chon cua ban khong hop le!!!";
            cout << "Hay nhap lai: ";
            cin >> luachon;
        }
        system("cls");
        switch (luachon)
        {
        case 1:
           {     cout << "Nhap lai ten: ";
                cin.ignore();
                getline(cin, New);
                p->data.name = New;
            break;}
        case 2:
          {      string newAddress;
                cout << "Nhap lai dia chi: ";
                cin.ignore();
                getline(cin, newAddress);
                 p->data.address = newAddress;
            break;}
         case 3:
           {     string newCCCD;
                cout << "Nhap so CCCD moi: ";
                cin.ignore();
                getline(cin, newCCCD);
                 p->data.cccd = newCCCD;
            break;}
        case 4:
          {  string sbdnew;
                cout << "Nhap so bao danh moi: ";
                cin.ignore();
                getline(cin, sbdnew);
                 p->data.sbd = sbdnew;
            break;}
            case 5:
       {   int day, month, year;
                cout << "Nhap lai ngay/thang/nam sinh: " << endl;
                cout << "Nhap ngay: ";
                cin >> day;
                cout << "Nhap thang: ";
                cin >> month;
                cout << "Nhap nam: ";
                cin >> year;
                p->data.date.day = day;
                p->data.date.month = month;
                p->data.date.year = year;
            break;}
        case 6:
          {       string newgt;
                cout << "Nhap gioi tinh: (0: Nam, 1: Nu) ";
                cin >> newgt;
                p->data.gt = newgt;
            break;}
        case 7:
          {  float newMath, newPhysics, newChemistry;
                cout << "Nhap diem toan: ";
                cin >> newMath;
                cout << "Nhap diem ly: ";
                cin >> newPhysics;
                cout << "Nhap diem hoa: ";
                cin >> newChemistry;
                p->data.to=newMath;
                p->data.to=newPhysics;
                p->data.ho = newChemistry;
            break;}
        }
        cout << "Ban co muon sua thong tin nao nua khong? (y/n) ";
        cin >> c;
    } while (c == "y" || c == "Y");
}
float tim_nghanh(string s)
{
    string str ;
    int result ;
    mofile();
    Nganhdaotao *p = pHead;
            while (p != NULL)
            {
                result = strcmp(p->TenNganh.c_str(), s.c_str());
                if (result == 0){
                    return p->DiemChuan;
                }
                p = p->next;
            }
    cout << "Khong co ten nganh nay !" << endl;
        return 0;
}
LinkedList check_dau(LinkedList &ds){
    LinkedList dsdau;
    node *p = ds.head;
    float dc;
    while (p!=NULL)
    {
        int i=0;
        do
        {
            if (dc=tim_nghanh(p->data.wishes[i])) {
                if (p->data.sum >= dc)
                   { dsdau.insert(p->data);break;}
            }
            else 
            {cout<<"Khong co ten nganh da nhap";
            break;
            }
         i++;    
        }
        while(i<p->data.wishes.size());
        p=p->next;
    }
    return dsdau;
}

