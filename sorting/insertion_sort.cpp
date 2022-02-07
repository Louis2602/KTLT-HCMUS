// thuat toan sap xep chen
#include <iostream>
#include <limits>
using namespace std;

void insertionSort(int arr[], int n)
{
    int j;
    // neu co 1 phan tu thi khong can sap xep, vi vay ta chay i tu 1
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void insertionSort_sentinel(int arr[], int n)
{
    int j;
    // neu co 1 phan tu thi khong can sap xep, vi vay ta chay i tu 1
    // our sentinel will be placed at the prev position of the first index and its value is smaller than the smallest value in the array
    // or we could say, our sentinel will be negative infinity
    arr[-1] = -numeric_limits<int>::infinity();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        j = i - 1;
        while (key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int binarySearch(int arr[], int val, int l, int r)
{
    // using binary search to find the min value in the array
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] >= val)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
int binarySearch_recursive(int arr[], int val, int l, int r)
{
    if (l == r)
        return arr[l] > val ? l : l + 1;
    if (l > r)
        return l;
    int mid = (l + r) / 2;
    return arr[mid] > val ? binarySearch_recursive(arr, val, l, mid - 1) : binarySearch_recursive(arr, val, mid + 1, r);
}
void insertionSort_binary_search(int arr[], int n)
{
    int j, pos, val;
    for (int i = 1; i < n; i++)
    {
        val = arr[i];
        j = i - 1;
        pos = binarySearch_recursive(arr, val, 0, j);
        while (j >= pos)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {1, 3, 7, 4, 6, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // insertionSort(arr, n);
    // insertionSort_sentinel(arr, n);
    insertionSort_binary_search(arr, n);
    printArray(arr, n);

    return 0;
}