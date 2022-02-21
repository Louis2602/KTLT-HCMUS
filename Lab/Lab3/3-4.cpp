#include <iostream>
using namespace std;

void inputArray(int *a, int &n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    inputArray(a, n);
    printArray(a, n);
    delete[] a;
    return 0;
}