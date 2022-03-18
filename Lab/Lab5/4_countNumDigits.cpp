#include <iostream>
using namespace std;

int countNumDigits(int n)
{
    if (n < 10)
        return 1;
    return 1 + countNumDigits(n /= 10);
}
int main()
{
    int n;
    cin >> n;
    int ans = countNumDigits(n);
    cout << "Number of digits = " << ans;
    return 0;
}