#include <iostream>
#include <fstream>
using namespace std;

void createBINfile()
{
    int n;
    float degree, coefficient;
    ifstream in("POLY.TXT");
    ofstream out("POLY.BIN", ios::binary);
    while (!in.eof())
    {
        in >> n;
        out.write(reinterpret_cast<char *>(&n), sizeof(n));
        for (int i = 1; i <= n; i++)
        {
            in >> degree >> coefficient;
            out.write(reinterpret_cast<char *>(&degree), sizeof(degree));
            out.write(reinterpret_cast<char *>(&coefficient), sizeof(coefficient));
        }
    }
    in.close();
    out.close();
}
void readBINfile()
{
    int n;
    float degree, coefficient;
    ifstream in("POLY.BIN", ios::binary);
    while (!in.eof())
    {
        if (in.read(reinterpret_cast<char *>(&n), sizeof(n)))
            cout << n << '\n';
        if (in.eof())
            break;
        for (int i = 1; i <= n; i++)
        {
            in.read(reinterpret_cast<char *>(&degree), sizeof(degree));
            in.read(reinterpret_cast<char *>(&coefficient), sizeof(coefficient));
            cout << degree << ' ' << coefficient << '\n';
        }
    }
    in.close();
}
int main()
{
    createBINfile();
    readBINfile();
    return 0;
}