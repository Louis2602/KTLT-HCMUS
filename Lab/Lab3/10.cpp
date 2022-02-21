#include <iostream>
using namespace std;

void swapArrays(int *a, int *b, int &na, int &nb)
{
    int na_new = min(na, nb);
    int nb_new = max(na, nb);
    for (int i = 0; i < nb_new; i++)
    {
        int tmp = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = tmp;
    }
    cout << "Array B: ";
    for (int i = 0; i < nb_new; i++)
        cout << *(b + i) << " ";
    cout << '\n';
    cout << "Array A: ";
    for (int i = 0; i < na_new; i++)
        cout << *(a + i) << " ";
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    int na = 4;
    int b[3] = {5, 6, 7};
    int nb = 3;
    swapArrays(a, b, na, nb);
    return 0;
}