#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == x)
            return mid;
        else
        {
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }
    }
    return 0;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == 0)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}