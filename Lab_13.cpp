#include <iostream>
#include "Book.h"

using namespace std;

void Smena_Imeni(string Rename, TelBook& Book) {
    Book.Set_Name(Rename); 
}


void Smena_Namber(string NewNam, TelBook& Book) {
    for (int i = 0; i < 11; i++)
        Book.Set_Namber(i, NewNam[i] - 0x30);
}


TelBook Back(TelBook& Book2) {
    TelBook Tel;
    Tel.Set_Name(Book2.Get_Name());
    for (int i = 0; i < 11;i++)
    Tel.Set_Namber(i,Book2.Get_Namber(i));
    return Tel;
}   


int main() {
    setlocale(LC_ALL, ".1251");
    int K;
    char q;
    string New_name, New_namber;
    cout << "Введите количество номеров:";
    cin >> K;
    TelBook* b1= new TelBook[K];
    TelBook* b2 = new TelBook[2];
    for (int i = 0; i < K;i++) {
        cin >> b1[i];
        cout << b1[i];
    cout << "Данные введены верно? Y-да N-нет: ";
    cin >> q;

    if (q == 'N' || q == 'n') {
        cout << "Измените имя:";
        cin >> New_name;
        Smena_Imeni(New_name, b1[i]);
        cout << "Измените номер:";
            cin >> New_namber;
        while (New_namber.size() != 11)
        {
            cout << "Кол-во цифр должно быть равно 11!" << endl;
            cin >> New_namber;
        }
        Smena_Namber(New_namber, b1[i]);
        cout << b1[i];
    }
    }
    cout << "Копировать значения списка? Y-да N-нет:";
    cin >> q;
    if (q == 'Y' || q == 'y') {
        b2[0] = Back(b1[0]);
        cout << b2[0];
    }
    system("PAUSE");
}