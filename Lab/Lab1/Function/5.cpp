#include <iostream>
using namespace std;

int sumDigits(int n)
{
    int s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}
int main()
{
    int n;
    cin >> n;
    int ans = sumDigits(n);
    cout << "Sum of digits: " << ans << endl;
    return 0;
}