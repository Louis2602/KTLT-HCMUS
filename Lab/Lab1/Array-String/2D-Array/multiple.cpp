#include <iostream>
#include <ctime>
using namespace std;
void input(int a[][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            a[i][j] = rand() % 10;
    }
}
void multiple2DArray(int a[][100], int b[][100], int res[][100], int m, int n, int q)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < q; j++)
            for (int k = 0; k < n; k++)
                res[i][j] += (a[i][k] * b[k][j]);
}
void print(int res[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << res[i][j] << " ";
        cout << '\n';
    }
}
int main()
{
    srand(time(0));
    int ma, na, mb, nb;
    int a[100][100], b[100][100], res[100][100];
    cout << "Rows and Cols for matrix A: ";
    cin >> ma >> na;
    cout << "Rows and Cols for matrix B: ";
    cin >> mb >> nb;
    cout << "Matrix A:\n";
    input(a, ma, na);
    print(a, ma, na);
    cout << "Matrix B:\n";
    input(b, mb, nb);
    print(b, mb, nb);
    if (na == mb)
    {
        cout << "Product of 2 matrix A and B:\n";
        multiple2DArray(a, b, res, ma, na, nb);
        print(res, ma, nb);
    }
    else
        cout << "Error! Matrix cannot be multiplied";

    return 0;
}