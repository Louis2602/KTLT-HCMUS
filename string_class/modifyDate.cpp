#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    string m, d, y;
    getline(cin, m, '/');
    getline(cin, d, '/');
    getline(cin, y, '\n');
    int month = atoi(m.c_str());
    int day = atoi(d.c_str());
    int year = atoi(y.c_str());
    string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    cout << months[month - 1] << " " << day << ", " << year << '\n';
    return 0;
}