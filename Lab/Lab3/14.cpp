#include <iostream>
using namespace std;

int **generateMatrix2(int *a, int *b, int na, int nb)
{
    int **c = new int *[na];
    for (int i = 0; i < na; i++)
    {
        *(c + i) = new int[nb];
        for (int j = 0; j < nb; j++)
            *(*(c + i) + j) = *(a + i) * *(b + j);
    }
    return c;
}

int *generate(int *a, int *b, int na, int nb)
{
    int *c = new int[na + nb];
    for (int i = 0; i < na; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            *(c + i * na + j) = *(a + i) * *(b + j);
        }
    }
    return c;
}
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {2, 2, 3, 4, 6};
    // int **c;

    // c = generateMatrix2(a, b, 5, 5);
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //         cout << *(*(c + i) + j) << " ";
    //     cout << '\n';
    // }
    int *c = generate(a, b, 5, 5);
    for (int i = 0; i < 25; i++)
    {
        if (i % 5 == 0)
            cout << '\n';
        cout << *(c + i) << " ";
    }
    return 0;
}