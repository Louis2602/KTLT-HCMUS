#include <iostream>
using namespace std;

void input2DArray(int a[][100], int m, int n)
{
    cout << "Input\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}
void rotate2DArray(int matrix[][100], int m, int n)
{
    // transpose matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    // flip horizontally
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n / 2; ++j)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = tmp;
        }
    }
}
void print2DArray(int a[][100], int m, int n)
{
    cout << "Output\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    int a[100][100];
    int m, n;
    cin >> m >> n;
    input2DArray(a, m, n);
    rotate2DArray(a, m, n);
    print2DArray(a, m, n);
    return 0;
}