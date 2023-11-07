#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include"person.h"
#include"mylib.h"
using namespace std;
class ThiSinh : public Person
{
public:
    string sbd;
    float to, li, ho;
    float sum =to +li +ho;
    vector<string> wishes;
    ThiSinh();
    ThiSinh(string cccd, string name, Date date, string address, string gt, string sbd, float to, float li, float ho, vector<std::string> w);
    void input();
    void display();
    ~ThiSinh(){
        
    }
};

ThiSinh::ThiSinh() : Person()
{
    to = 0;
    sbd = "";
    li = 0;
    ho = 0;
}
ThiSinh::ThiSinh(string cccd, string name, Date date, string address, string gt, string sbd, float to, float li, float ho, vector<std::string> w) : Person(cccd, name, date, address, gt), sbd(sbd), to(to), li(li), ho(ho){
    wishes = w;
};
void ThiSinh::input()
{
    draw(60, 2, 112, 21);
    SetColor1(7, 4);
    nhapthongtin();
    fflush(stdin);
     gotoXY(62,11);
    cout  << "So bao danh: ";
    getline(cin, sbd);
     gotoXY(62,12);
    cout << "Diem toan: ";
    cin >> to;
     gotoXY(62,13);
    cout  << "Diem ly: ";
    cin >> li;
     gotoXY(62,14);
    cout << "Diem hoa: ";
    cin >> ho;
     gotoXY(62,15);
    int so_nv;
    cout << "So nguyen vong dang ki : " ;
    cin >> so_nv;
    fflush(stdin);
    for (int i = 0; i < so_nv; i++){
        string nv;
         gotoXY(62,16+i);
        cout << "Nguyen vong thu " << i+1 << " : " ;
        cin.ignore();
        getline(cin,nv);
        wishes.push_back(nv);
    }
}
void ThiSinh::display()
{
     cout << "|";
     for (int i = 0; i < 153; i++)
         cout << "-";
     cout << "|" << endl;
     cout << "|" << name << setw(34 - name.length()) << "|";
     cout << cccd << setw(20 - cccd.length()) << "|";
     cout << setw(4) << gt << setw(4) << "|";
     cout << date.day << "/" << date.month << "/" << date.year << setw(19 - date.sizedate()) << "|";
     cout << address<< setw(20 - address.length()) << "|";
     cout << sbd << setw(16 - sbd.length()) << "|";
     cout << setw(7) << to << setw(3) << "|";
     cout << setw(5) << li << setw(3) << "|";
     cout << setw(6) << ho << setw(3) << "|";
     cout << setw(5) << to + li + ho << setw(5) << "|" ;
   
//    cout << name << " " << cccd << " " << gt << " " << date.day << "/" << date.month << "/" << date.year << " " << address << " " << sbd << " " 
//    << to << " " << li << " " << ho << " " << to+li+ho << " ";
//    for (string wish : wishes) {
//                cout << wish << " ";
//            }
    cout << endl;
}


 