#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[] = {6, 4, 8, 0, 2, 11, 8, 1, 9, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);

    int minV, maxV;
    minV = min(a[0], a[1]);
    maxV = max(a[0], a[1]);
    for (int i = 2; i < n; i += 2)
    {
        if (a[i] > a[i + 1])
        {
            minV = min(a[i + 1], minV);
            maxV = max(a[i], maxV);
        }
        else
        {
            minV = min(a[i], minV);
            maxV = max(a[i + 1], maxV);
        }
    }
    cout << "Max = " << maxV << " and Min = " << minV << '\n';
    return 0;
}