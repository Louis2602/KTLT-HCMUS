#include <iostream>
using namespace std;

void sortArray(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i % 2 == 0 && a[i] < a[j])
                swap(a[i], a[j]);
            else if (i % 2 != 0 && a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}
void output(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[7] = {20, 50, 60, 10, 40, 30, 70};
    sortArray(a, 7);
    output(a, 7);
    return 0;
}
