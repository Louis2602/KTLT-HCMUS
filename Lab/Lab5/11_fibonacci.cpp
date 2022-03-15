#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int improvedFibonacci(int n, int *cache)
{
    if (cache[n])
        return cache[n];
    cache[n] = improvedFibonacci(n - 1, cache) + improvedFibonacci(n - 2, cache);
    return cache[n];
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
    int cache[3] = {0, 1, 1};
    cout << "Fibonacci at " << n << "th = " << improvedFibonacci(n, cache);
    return 0;
}