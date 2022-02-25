#include <iostream>
using namespace std;

void shakerSort(int a[], int n)
{
    int l, r, mark;
    l = 0;
    r = mark = n - 1;
    while (l < r)
    {
        for (int j = l; j < r; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                mark = j;
            }
        }
        r = mark;
        for (int i = r; i > l; i--)
        {
            if (a[i] < a[i - 1])
            {
                int tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
                mark = i;
            }
        }
        l = mark;
    }
}
void shakerSort_2(int a[], int n)
{
    int l = 0, r = n - 1;
    for (int i = l; i < r; i++)
    {
        for (int j = r; j > l; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        l++;
        for (int j = l; j < r; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        r--;
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int a[] = {9, 8, 7, 5, 3, 6, 1};
    int n = 7;
    shakerSort_2(a, n);
    print(a, n);
    return 0;
}