#include <iostream>
using namespace std;

void sum2DArray(int a[][100], int b[][100], int res[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            res[i][j] = a[i][j] + b[i][j];
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
    int a[100][100] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, b[100][100] = {{2, 3, 1}, {4, 4, 3}, {9, 6, 5}}, res[100][100];
    int m = 3, n = 3;
    sum2DArray(a, b, res, m, n);
    cout << "Array A\n";
    print(a, m, n);
    cout << "Array B\n";
    print(b, m, n);
    cout << "Resutl\n";
    print(res, m, n);
    return 0;
}