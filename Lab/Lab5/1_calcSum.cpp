#include <iostream>
using namespace std;

int Sum(int n)
{
    if (n < 1)
        return n;
    return n + Sum(n - 1);
}
int main()
{
    int n;
    cin >> n;
    int ans = Sum(n);
    cout << "Sum = " << ans;
    return 0;
}