#include <iostream>

using namespace std;

int calcReverseValue(int n, int ans)
{
    if (n == 0)
        return ans;
    ans = ans * 10 + n % 10;
    return calcReverseValue(n /= 10, ans);
}
int main()
{
    int n;
    cin >> n;
    cout << "Reverse value of n = " << calcReverseValue(n, 0);
    return 0;
}