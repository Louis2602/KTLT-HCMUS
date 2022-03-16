#include <iostream>
#include <cstring>

using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int memoizationFib(int n, int *cache)
{
    if (n <= 1)
        return n;
    if (cache[n] != 0)
        return cache[n];
    else
    {
        cache[n] = memoizationFib(n - 1, cache) + memoizationFib(n - 2, cache);
        return cache[n];
    }
}
int main()
{
    int n;
    cin >> n;
    // cout << "Fibonacci at " << n << "th = " << fibonacci(n);
    // long long f0 = 0, f1 = 1, f;
    // for (int i = 2; i <= n; i++)
    // {
    //     f = f0 + f1;
    //     f0 = f1;
    //     f1 = f;
    // }
    // cout << f;
    int cache[1000];
    memset(cache, 0, sizeof(cache));
    cout << "Fibonacci at " << n << "th = " << memoizationFib(n, cache);
    return 0;
}