// thuat toan sap xep chen
#include <iostream>
#include <limits>
using namespace std;

// Thuật toán sắp xếp chèn

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
    // arr[-1] = -numeric_limits<int>::infinity();
    arr[-1] = -1e7;
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
void insertionSort_sentinel_2(int arr[], int n)
{
    int j;
    // neu co 1 phan tu thi khong can sap xep, vi vay ta chay i tu 1
    // our sentinel will be placed at the prev position of the first index and its value is smaller than the smallest value in the array
    // or we could say, our sentinel will be negative infinity
    // arr[-1] = -numeric_limits<int>::infinity();
    int temp = arr[0];
    arr[0] = -1e7;
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
    j = 1;
    while (arr[j] < temp && j < n)
    {
        arr[j - 1] = arr[j];
        j++;
    }
    arr[j - 1] = temp;
}
int binarySearch(int arr[], int val, int l, int r)
{
    // using binary search to find the min value in the left-half array from 0 to j
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
void binaryInsertionSort_2(int a[], int n)
{
    int l, r, mid;
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        l = 0;
        r = i - 1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (key >= a[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        for (int j = i; j > l; j--)
            a[j] = a[j - 1];
        a[l] = key;
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {6, 3, 8, 4, 1, 7, 2, 1, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    // insertionSort_sentinel(arr, n);
    // insertionSort_binary_search(arr, n);
    // binaryInsertionSort_2(arr, n);
    // insertionSort_sentinel_2(arr, n);
    printArray(arr, n);

    return 0;
}
