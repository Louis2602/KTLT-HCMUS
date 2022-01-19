// thuat toan doi cho truc tiep
#include <iostream>
using namespace std;

int main()
{
    int a[] = {5, 3, 6, 1, 7, 2, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);

    // swaping elements directly
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j])
                swap(a[i], a[j]);

    // print
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}