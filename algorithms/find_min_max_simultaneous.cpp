#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[] = {6, 4, 8, 0, 2, 11, 8, 1, 9, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);

    int prev_min = a[0], prev_max = a[0];
    int curr_min, curr_max;
    for (int i = 0; i < n - 1; i += 2)
    {
        if (a[i] < a[i + 1])
        {
            curr_min = a[i];
            curr_max = a[i + 1];
        }
        else
        {
            curr_min = a[i + 1];
            curr_max = a[i];
        }
        curr_min = min(curr_min, prev_min);
        curr_max = max(curr_max, prev_max);
        prev_min = curr_min;
        prev_max = curr_max;
    }
    cout << "Max = " << curr_max << " and Min = " << curr_min << '\n';
    return 0;
}