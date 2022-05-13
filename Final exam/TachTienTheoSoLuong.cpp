#include <iostream>
using namespace std;
 
int b[1000];
 
bool solve(int n, int cnt, int x)
{
    int a[5] = {1, 2, 5, 10};
    if (n < 0 || cnt < 0)
        return false;
    if (n == 0 && cnt == 0)
    {
        b[cnt] = x;
        return true;
    }
    bool ans = false;
    for (int i = 0; i < 4; i++)
    {
        ans = solve(n - a[i], cnt - 1, a[i]);
        if (ans)
        {
            b[cnt] = x;
            return true;
        }
    }
    return false;
}
 
int main()
{
    int n = 29;
    int cnt = 6;
    cout << solve(n, cnt, 0) << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}