#include <iostream>
#include <algorithm>
using namespace std;

void min_max(int n, int arr[])
{
    if (n < 1)
    {
        cout << "None";
        return;
    }
    int tmin = arr[0];
    int tmax = arr[0];

    int i = 1;
    int a, b;
    int x, y;
    while (i < n)
    {
        a = arr[i];
        if (i + 1 < n)
            b = arr[i + 1];
        else
            a;
        if (a <= b)
        {
            x = a;
            y = b;
        }
        else
        {
            x = b;
            y = a;
        }
        tmin = min(x, tmin);
        tmax = max(y, tmax);
        i += 2;
    }
    cout << "Min = " << tmin << " Max = " << tmax << '\n';
}

int main()
{
    int arr[] = {3, 2, 5, 6, 1, 9, 7, 13, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    min_max(n, arr);
    return 0;
}