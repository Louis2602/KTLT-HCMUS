#include <iostream>
using namespace std;

int search(int a[], int k, int n)
{
    a[n] = k; // we need a sentinel to break the loop
    int i = 0;
    while (a[i] != k)
        i++;
    if (i == n)
        return -1;
    return i;
}

int main()
{
    int a[] = {10, 3, 2, 6, 8, 12, 15};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 8;
    // cout << search(a, k, n);
    printf("%d", search(a, k, n));
    // if (search(a, k, n))
    //     cout << "k is in the array";
    // else
    //     cout << "k is not in the array";
    return 0;
}