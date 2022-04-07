#include <iostream>
using namespace std;

int findEven(int n, int ans, int i)
{
    if (n == 0)
        return ans;
    if ((n % 10) % 2 == 0)
        ans = ans + (n % 10) * i;
    return (n % 10) % 2 == 0 ? findEven(n /= 10, ans, i *= 10) : findEven(n /= 10, ans, i);
}
int main()
{
    int n;
    cin >> n;
    int ans;
    ans = findEven(n, 0, 1);
    cout << ans;
    return 0;
}