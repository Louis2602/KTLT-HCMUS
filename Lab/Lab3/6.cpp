#include <iostream>
using namespace std;

int *copyArray(int *a, int n)
{
    int *newArray = new int[n];
    for (int i = 0; i < n; i++)
        *(newArray + i) = *(a + i);
    return newArray;
}

int main()
{
    int a[5] = {3, 2, 4, 1, 5};
    int n = 5;
    int *newArray = copyArray(a, n);
    cout << "Copied Array: ";
    for (int i = 0; i < n; i++)
        cout << *(newArray + i) << " ";
    return 0;
}