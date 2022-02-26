#include <iostream>
using namespace std;

int *findLargestTotalSubarray(int *a, int n, int &total)
{
    total = *a;
    int curr_max = a[0];
    for (int i = 0; i < n; i++)
    {
        curr_max = max(*(a + i), curr_max + *(a + i));
        total = max(total, curr_max);
    }
    return &total;
}
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int total;
    int *ans;
    ans = findLargestTotalSubarray(a, n, total);
    cout << "Maximum contiguous sum is: " << *ans;
    return 0;
}