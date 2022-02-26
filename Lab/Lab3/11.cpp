#include <iostream>
using namespace std;

int *concatenate2Arrays(int *a, int *b, int na, int nb)
{
    int *c = new int[na + nb];
    for (int i = 0; i < na + nb; i++)
    {
        *(c + i) = *(a + i);
        if (i > na - 1)
        {
            *(c + i) = *(b + i - na);
        }
    }
    return c;
}

int main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8, 9, 10};
    int na = sizeof(a) / sizeof(a[0]);
    int nb = sizeof(b) / sizeof(b[0]);
    int *ans;
    ans = concatenate2Arrays(a, b, na, nb);
    for (int i = 0; i < na + nb; i++)
        cout << *(ans + i) << " ";
    delete[] ans;
    return 0;
}