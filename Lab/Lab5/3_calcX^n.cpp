#include <iostream>
using namespace std;

int calcXn(int x, int n)
{
    if (n < 2)
        return x;
    return x * calcXn(x, n - 1);
}
int main()
{
    int n, x;
    cout << "Nhap co so: ";
    cin >> x;
    cout << "Nhap so mu: ";
    cin >> n;
    int ans = calcXn(x, n);
    cout << "X^n = " << ans;
    return 0;
}