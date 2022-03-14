#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int countNumberOfDivisors(int g, int i)
{
    if (g == i)
        return 1;
    return g % i == 0 ? 1 + countNumberOfDivisors(g, ++i) : countNumberOfDivisors(g, ++i);
}
int main()
{
    int a, b;
    cin >> a >> b;
    int ans = countNumberOfDivisors(gcd(a, b), 1);
    cout << "Number of divisors: " << ans;
    return 0;
}