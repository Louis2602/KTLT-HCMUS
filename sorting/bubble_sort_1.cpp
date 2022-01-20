#include <iostream>
using namespace std;

int main()
{
    int a[] = {11, 8, 5, 2, 7, 1};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}