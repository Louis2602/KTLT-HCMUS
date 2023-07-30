#include <iostream>
using namespace std;

void output(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void evenOddAscendingSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // even meets smaller even => swap
            // odd meets smaller odd => swap
            if ((arr[i] % 2 == 0 && arr[j] % 2 == 0 && arr[i] > arr[j]) ||
                (arr[i] % 2 != 0 && arr[j] % 2 != 0 && arr[i] > arr[j]))
            {
                swap(arr[i], arr[j]);
            }
            // odd meets even => swap
            else if (arr[i] % 2 != 0 && arr[j] % 2 == 0)
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    // int arr[10] = {2, 1, 3, 7, 4, 8, 9, 13, 11, 6};
    int arr[10] = {2, 18, 7, 4, 8, 9, 11, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    evenOddAscendingSort(arr, n);
    output(arr, n);
    cout << n << endl;
    return 0;
}