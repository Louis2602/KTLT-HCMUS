#include <iostream>
using namespace std;

int calcBinaryValue_1(int n, int cnt, int ans)
{
    if (n == 0)
        return ans;
    ans = ans + (n % 2) * cnt;
    return calcBinaryValue_1(n /= 2, cnt *= 10, ans);
}

int *calcBinaryValue_2(int n, int &i, int &m, int *a)
{
    if (n == 0)
        return a;
    a[i] = n % 2;
    return calcBinaryValue_2(n /= 2, ++i, ++m, a);
}
int main()
{
    int n;
    cin >> n;
    // int ans = calcBinaryValue_1(n, 1, 0);
    // cout << "Binary value of " << n << " = " << ans;
    int a[100];
    int i = 0, m = -1;
    int *ans = calcBinaryValue_2(n, i, m, a);
    for (int i = m; i >= 0; i--)
        cout << a[i];
    return 0;
}