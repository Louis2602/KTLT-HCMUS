#include <iostream>
#include <ctime>

using namespace std;

int **generateMatrix(int **a, int &width, int &length)
{
    srand(time(NULL));
    a = new int *[width];
    for (int i = 0; i < width; i++)
    {
        a[i] = new int[length];
        for (int j = 0; j < length; j++)
            a[i][j] = rand() % 10 - 5;
    }
    return a;
}
void print(int **a, int width, int length)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
}
void findMaxSumSubmatrix(int **a, int width, int length, int width_, int length_)
{
    int maxSum = 0, currSum = 0;
    for (int i = 0; i < width - width_ + 1; i++)
    {
        for (int j = 0; j < length - length_ + 1; j++)
        {
            currSum = 0;
            for (int m = i; m < i + width_; m++)
            {
                for (int n = j; n < j + length_; n++)
                {
                    currSum += a[m][n];
                }
            }
            cout << currSum << " ";
            maxSum = max(maxSum, currSum);
        }
        cout << '\n';
    }
    cout << "Max sum submatrix is: " << maxSum;
}
int main()
{
    int **a;
    int width, length;
    cout << "Enter matrix width: ";
    cin >> width;
    cout << "Enter matrix length: ";
    cin >> length;
    int **matrix;
    matrix = generateMatrix(a, width, length);
    print(matrix, width, length);
    int width_, length_;
    cout << "Enter submatrix width: ";
    cin >> width_;
    cout << "Enter submatrix length: ";
    cin >> length_;
    findMaxSumSubmatrix(matrix, width, length, width_, length_);
    return 0;
}