#include <iostream>
using namespace std;

bool search(int a[], int k, int n)
{
    a[n] = k; // we need a sentinel to break the loop
    int i = 0;
    while (a[i] != k)
        i++;
    return i < n;
}

int main()
{
    int a[] = {10, 3, 2, 6, 8, 12, 15};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 7;
    if (search(a, k, n))
        cout << "k is in the array";
    else
        cout << "k is not in the array";
    return 0;
}