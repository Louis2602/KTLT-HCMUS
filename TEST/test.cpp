#include <iostream>

using namespace std;

int isPrime(int n)
{
  if (n <= 1)
    return false;
  for (int i = 2; i <= n / 2; i++)
    if (n % i == 0)
      return false;

  return true;
}

int sumOfPrimeDivisor(int n, int m)
{
  if (n == 0)
    return 0;
  if (isPrime(n) && m % n == 0)
    cout << n << endl;
  return (isPrime(n) && m % n == 0) ? n + sumOfPrimeDivisor(n - 1, m)
                                    : sumOfPrimeDivisor(n - 1, m);
}

void printMatrixA(int **A, int p, int q)
{
  for (int i = 0; i < p; i++)
  {
    for (int j = 0; j < q; j++)
    {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}

int **generateCMatrix(int **A, int p, int q, int n)
{
  int minSum = 1000, maxSum = A[0][0], currSum = 0;
  int xMin, yMin;
  int xMax, yMax;
  for (int i = 0; i < p - n + 1; i++)
  {
    for (int j = 0; j < q - n + 1; j++)
    {
      currSum = 0;
      for (int m = i; m < i + n; m++)
      {
        for (int k = j; k < j + n; k++)
        {
          currSum += A[m][k];
        }
      }
      if (minSum > currSum)
      {
        minSum = currSum;
        xMin = i;
        yMin = j;
      }
      if (maxSum < currSum)
      {
        maxSum = currSum;
        xMax = i;
        yMax = j;
      }
    }
  }
  int **C = new int *[n];
  for (int i = 0; i < n; i++)
  {
    C[i] = new int[2 * n];
    for (int j = 0; j < 2 * n; j++)
    {
      if (j < n)
        C[i][j] = A[xMin + i][yMin + j];
      else
        C[i][j] = A[xMax + i][yMax + j - n];
    }
  }
  return C;
}

void deleteMatrix(int **matrix, int rows)
{
  for (int i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}

int main()
{
  // p = row = 6, q = col = 6
  int A[6][6] = {{1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, {1, 1, 1, 3, 3, 3}, {1, 1, 1, 3, 3, 3}, {1, 1, 1, 3, 3, 3}};
  // Convert 2D array to pointer to pointer
  int *ptrToPtr[6];
  for (int i = 0; i < 6; i++)
    ptrToPtr[i] = A[i];

  int p = 6; // Number of rows
  int q = 6; // Number of columns
  int n = 4; // Size of submatrix
  printMatrixA(ptrToPtr, p, q);

  int **C = generateCMatrix(ptrToPtr, p, q, n);

  cout << "Matrix C:" << endl;
  printMatrixA(C, n, 2 * n);

  // Deallocate memory for matrix C
  deleteMatrix(C, n * 2);

  return 0;
}
