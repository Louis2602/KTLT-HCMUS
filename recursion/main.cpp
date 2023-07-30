#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int fib0 = 0;
    int fib1 = 1;
    int n = 8;
    int fib;
    for (int i = 0; i < n - 1; ++i)
    {
        fib = fib1 + fib0;
        int tmp = fib1;
        fib1 = fib;
        fib0 = tmp;
    }
    cout << fib << endl;
    cout << fibo(8) << endl;
    return 0;
}