#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << "GCD = " << gcd(a, b) << "\nLCM = " << lcm(a, b) << "\n";
    return 0;
}