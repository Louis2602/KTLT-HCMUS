#include <iostream>
using namespace std;

void printSMatrix(int A[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}
void generateCMatrix(int A[][3], int B[][6], int na, int nb, int C[][10])
{
    int minSum = 1000, currSum = 0;
    int x, y;
    for (int i = 0; i < nb - na + 1; i++)
    {
        for (int j = 0; j < nb - na + 1; j++)
        {
            currSum = 0;
            for (int m = i; m < i + na; m++)
                for (int n = j; n < j + na; n++)
                    currSum += B[m][n];
            if (minSum > currSum)
            {
                minSum = currSum;
                x = i;
                y = j;
            }
        }
    }
    int k = 0, l = 0;
    for (int i = 0; i < nb; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if (i >= x && j < na + y && k < na && j >= y)
            {
                C[i][j] = A[k][l];
                l++;
            }
            else
                C[i][j] = B[i][j];
            cout << C[i][j] << " ";
        }
        if (i >= x)
        {
            k++;
            l = 0;
        }
        cout << '\n';
    }
}
int main()
{
    int A[3][3] = {
        {5, 5, 5},
        {5, 5, 5},
        {5, 5, 5}};
    int B[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 1, 1, 0, 3, 3},
        {1, 1, 1, 0, 3, 3},
        {1, 1, 1, 0, 3, 3}};
    int na = 3, nb = 6;
    // printSMatrix(A, na);
    int C[10][10];
    generateCMatrix(A, B, na, nb, C);
    return 0;
}