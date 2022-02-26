#include <iostream>
using namespace std;

int *findLongestAscendingSubarray(int *a, int n)
{
    static int length = 0;
    int curr_length;
    for (int i = 0; i < n - 1; i++)
    {
        curr_length = 1;
        for (int j = i; j < n; j++)
        {
            if (*(a + j) < *(a + j + 1))
                curr_length++;
            else
                break;
        }
        length = max(curr_length, length);
    }
    return &length;
}

int main()
{
    int a[] = {3, 4, 2, 5, 8, 7, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int *length;
    length = findLongestAscendingSubarray(a, n);
    cout << "Longest Ascending Subarray has length " << *length;
    return 0;
}