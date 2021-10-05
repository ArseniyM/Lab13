#include <string>
#include "Book.h"
using namespace std;

TelBook::TelBook() {
    Namber = new int[11];
    Name = "";
}

TelBook::TelBook(string name) {
    Namber = new int[11];
    Name = name;
}

TelBook::TelBook(const TelBook& CopiBook) {
    Namber = CopiBook.Namber;
    Name = CopiBook.Name;
}

TelBook::~TelBook() {
    Namber = NULL;
}

void TelBook::Set_Name(string s) {
    Name = s;
}

string TelBook::Get_Name() {
    return Name;
}

void TelBook::Set_Namber(int i, int n) {
    Namber[i] = n;
}

int TelBook::Get_Namber(int j) {
    return Namber[j];
}

istream& operator >>(istream& in, TelBook& a) {
    string s;
    if (a.Get_Name() == "") {
        cout << "Введите имя:";
        in >> s;
        a.Set_Name(s);
    }
    else {
        cout << "Имя: " << a.Get_Name() << endl;
    }
    s = "";
    cout << "Введите номер: ";
    in >> s;
    while (s.size()!=11)
    {
    cout << "Кол-во цифр должно быть равно 11!"<<endl;
    in >> s;
    }
    for (int i = 0; i < 11; i++)
        a.Set_Namber(i, s[i] - 0x30);
    return in;
}

ostream& operator <<(ostream& out, TelBook& a) {
    out << "Имя:" << a.Get_Name() << endl;
    out << "Номер: +" << a.Get_Namber(0) << " (";
    for (int i = 1; i <= 3; i++)
        out << a.Get_Namber(i);
    out << ") ";
    for (int i = 4; i <= 6; i++)
        out << a.Get_Namber(i);
    out << "-";
    for (int i = 7; i <= 8; i++)
        out << a.Get_Namber(i);
    out << "-";
    for (int i = 9; i <= 10; i++)
        out << a.Get_Namber(i);
    out << endl;
    return out;
}

TelBook& TelBook::operator=(const TelBook& zZz) {
    if (&zZz == this) return *this;
    Namber=zZz.Namber;
    Name = zZz.Name;
    return *this;
}