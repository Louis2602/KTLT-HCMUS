#include <iostream>
using namespace std;
void input(int a[][100], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
    }
}
void multiple2DArray(int a[][100], int b[][100], int res[][100], int m, int n, int q)
{
    if (m == q)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < q; j++)
                for (int k = 0; k < n; k++)
                    res[i][j] += (a[i][k] * b[k][j]);
    }
    else
    {
        cout << "Can't do multiplication on these matrix" << '\n';
    }
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
    int m, n, p, q;
    int a[100][100], b[100][100], res[100][100];
    cout << "Rows and Cols for matrix A: ";
    cin >> m >> n;
    cout << "Rows and Cols for matrix B: ";
    cin >> p >> q;
    cout << "Matrix A:\n";
    input(a, m, n);
    cout << "Matrix B:\n";
    input(b, p, q);
    cout << "Product of 2 matrix A and B:\n";
    multiple2DArray(a, b, res, m, n, q);
    print(res, m, q);
    return 0;
}