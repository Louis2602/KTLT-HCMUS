#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = a + 1; i < b; i++)
    {
        if (isPrime(i))
            cnt++;
    }
    cout << "The number of prime between " << a << " and " << b << " is " << cnt << '\n';
    return 0;
}