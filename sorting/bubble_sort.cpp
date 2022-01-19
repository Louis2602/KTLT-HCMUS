#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 2, 5, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // swaping adjacent elements
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    // output
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}