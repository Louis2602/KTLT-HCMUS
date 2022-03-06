#include <iostream>
#include <string>
#include <fstream>
using namespace std;

float Calc(string s, float a, float b)
{
    if (s == "+")
        return a + b;
    else if (s == "-")
        return a - b;
    else if (s == "*")
        return a * b;
    else
        return a / b;
}
int main()
{
    ifstream in;
    ofstream out;
    in.open("input1.txt");
    out.open("output1.txt");

    int n;
    in >> n;
    string s, sign;
    float ans;
    out << "Result\n";
    for (int i = 0; i < n; i++)
    {
        getline(in, s, ' ');
        getline(in, s, ' ');
        float x = stof(s);
        getline(in, sign, ' ');
        getline(in, s, '\n');
        float y = stof(s);
        // cout << x << " " << y << " " << sign << '\n';
        ans = Calc(sign, x, y);
        out << "- " << ans << endl;
    }
    in.close();
    out.close();
    return 0;
}
