#include <iostream>
using namespace std;

int main()
{
    int a[] = {0, 6, 4, 2, 3, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int j;
    int tmp = a[0];
    a[0] = -1e7;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        int k = a[i];
        while (k < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
    j = 1;
    while (a[j] < tmp && j < n)
        a[j - 1] = a[j];
    a[j - 1] = tmp;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}