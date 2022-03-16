#include <iostream>
using namespace std;

void printarray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

void permutation(int *arr, int start, int end)
{
    if (start == end)
    {
        printarray(arr, end + 1);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(*(arr + i), *(arr + start));
        permutation(arr, start + 1, end);
        swap(*(arr + i), *(arr + start));
    }
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int i;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cout << "All the permutations:\n";
    permutation(arr, 0, n - 1);
    return 0;
}
