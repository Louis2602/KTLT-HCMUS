#include <iostream>
using namespace std;

int countNumOddDigits(int n)
{
    if (n < 10 && n % 2 != 0 || n == 0)
        return 0;
    else
        return (n % 10) % 2 == 0 ? 1 + countNumOddDigits(n /= 10) : countNumOddDigits(n /= 10);
}
int main()
{
    int n;
    cin >> n;
    int ans = countNumOddDigits(n);
    cout << "Number of digits = " << ans;
    return 0;
}