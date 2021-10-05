#include <string>
#include <iostream>
using namespace std;
class TelBook {
private:
    string Name;
    int* Namber;
public:
    TelBook();
    TelBook(string name);
    TelBook(const TelBook&);
    ~TelBook();
    void Set_Name(string s);
    string Get_Name();
    void Set_Namber(int i, int n);
    int Get_Namber(int i);
    TelBook& operator=(const TelBook& zZz);
};

istream& operator >>(istream& in, TelBook& a);
ostream& operator <<(ostream& out, TelBook& a);