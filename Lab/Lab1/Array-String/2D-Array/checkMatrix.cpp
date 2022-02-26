#include <iostream>
#define N 4
using namespace std;

bool isUpperTriangularMatrix(int mat[N][N])
{
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (mat[i][j] != 0)
                return false;
    return true;
}
bool isLowerTriangularMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (mat[i][j] != 0)
                return false;
    return true;
}

bool isDiagonalMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
        if (mat[i][i] != 0)
            return false;
    return true;
}

int main()
{
    int mat[N][N] = {{1, 3, 5, 3},
                     {0, 4, 6, 2},
                     {0, 0, 2, 5},
                     {0, 0, 0, 6}};
    int mat1[N][N] = {{1, 0, 0, 0},
                      {1, 4, 0, 0},
                      {4, 6, 2, 0},
                      {0, 4, 7, 6}};
    int mat2[N][N] = {{0, 3, 5, 1},
                      {1, 0, 9, 3},
                      {4, 6, 0, 7},
                      {0, 4, 7, 0}};
    if (isDiagonalMatrix(mat2))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}