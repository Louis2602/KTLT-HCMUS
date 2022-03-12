#include <iostream>
using namespace std;
void bubbleSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int cnt = 0;
        for (int j = n - 1; j >= i; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                cnt++;
            }
        }
        if (cnt == 0)
            return;
    }
}
int main()
{
    int a[7] = {6, 4, 7, 2, 8, 1, 5};
    bubbleSort(a, 7);
    for (int i = 0; i < 7; i++)
        cout << a[i] << " ";
    return 0;
}