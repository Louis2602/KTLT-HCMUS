#include <iostream>
using namespace std;

int main()
{
    int a[] = {3, 4, 5, 6, 2, 1, 8, 0, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int *ptr = a;
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (*(ptr + i) > max)
            max = *(ptr + i);
    }
    cout << "Max: " << max;
    return 0;
}