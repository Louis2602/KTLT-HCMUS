// thuat toan sap xep chen
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int j;
    // neu co 1 phan tu thi khong can sap xep, vi vay ta chay i tu 1
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void insertionSort_sentinel(int arr[], int n)
{
}
void insertionSort_binary_search(int arr[], int n)
{
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // insertionSort(arr, n);
    insertionSort_sentinel(arr, n);
    printArray(arr, n);

    return 0;
}