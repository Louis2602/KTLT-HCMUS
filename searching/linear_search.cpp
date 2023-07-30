#include <iostream>
#include <cmath>
using namespace std;

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return 0;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 20;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = search(arr, n, x);
    (result == 0)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
