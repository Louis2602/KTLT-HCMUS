#include <iostream>
using namespace std;

int findEven(int n)
{
    if (n == 0)
        return 0;
    if (n % 2 == 0 && n < 10)
        return 1;
    return (n % 10) % 2 == 0 ? 1 + findEven(n /= 10) : findEven(n /= 10);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int ans = findEven(n);
    cout << "Number of even digits: " << ans;
    return 0;
}