#include <iostream>
using namespace std;
// Interpolation : phep noi suy
// Need a sorted array
// to have best performance, the array should be fairly uniform
int interpolationSearch(int b[], int n, int x)
{
    int l = 0, h = n - 1;

    while (l <= h && x >= b[l] && x <= b[h])
    {
        if (l == h)
        {
            if (b[l] == x)
                return l;
            return -1;
        }
        int pos = l + (float(h - l) / (b[h] - b[l])) * (x - b[l]);

        if (b[pos] == x)
            return pos;
        if (b[pos] < x)
            l = pos + 1;
        else
            h = pos - 1;
    }
    return -1;
}
int main()
{
    // all the gap between each elements in the array must be the same
    // Formula: l + (x - a[l])/(a[h] - a[l]) * (h - l), l=low, h=high, x:search
    int a[8] = {1, 3, 5, 7, 9, 11, 13, 15}; // gap = 2
    // or the gap is not the same
    int b[8] = {1, 3, 5, 14, 21, 25, 26, 27};
    int x = 24;
    int n = 8;
    int foundXPos = interpolationSearch(b, n, x);
    foundXPos == -1 ? cout << x << " was not found in the array" : cout << x << " was found at index: " << foundXPos;
    return 0;
}