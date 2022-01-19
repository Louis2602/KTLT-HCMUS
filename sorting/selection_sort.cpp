#include <iostream>
using namespace std;

int main()
{
    int a[] = {3, 2, 5, 1, 6, 4, 9, 7, 11};
    int n = sizeof(a) / sizeof(a[0]);

    int minIndex, minValue;

    // compare to the current min value and then swap if condition is true
    for (int i = 0; i < n - 1; ++i)
    {
        minIndex = i;
        minValue = a[i];
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < minValue)
            {
                minIndex = j;
                minValue = a[j];
            }
        }
        a[minIndex] = a[i];
        a[i] = minValue;
    }

    // output
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    return 0;
}
