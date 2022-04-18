#include <iostream>
#include <ctime>

using namespace std;

int **generateMatrix(int **A, int &length, int &width)
{
    srand(time(0));
    // Khoi tao mang 2 chieu
    A = new int *[width];
    for (int i = 0; i < width; i++)
    {
        // Khoi tao mang 1 chieu
        *(A + i) = new int[length];
        for (int j = 0; j < length; j++)
            *(*(A + i) + j) = rand() % 10 + -5;
    }
    cout << "Generated Matrix\n";
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
            cout << *(*(A + i) + j) << " ";
        cout << '\n';
    }
    return A;
}
int findSubmatrix(int **matrix, int length, int width, int &length_, int &width_)
{
    int maxSubmatrix = 0;
    int r = width;
    int c = length;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = i; k < width_; k++)
            {
                for (int l = j; l < length_; l++)
                {
                    int sumSubmatrix = 0;
                    for (int m = i; m <= k; m++)
                    {
                        for (int n = j; n <= l; n++)
                        {
                            sumSubmatrix += matrix[m][n];
                        }
                    }
                    maxSubmatrix = max(maxSubmatrix, sumSubmatrix);
                }
            }
        }
    }
    return maxSubmatrix;
}
int main()
{
    int **a;
    int length, width;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;
    int **matrix;
    matrix = generateMatrix(a, length, width);
    int ans, length_, width_;
    cout << "Enter submatrix length: ";
    cin >> length_;
    cout << "Enter submatrix width: ";
    cin >> width_;
    ans = findSubmatrix(matrix, length, width, length_, width_);
    cout << "Maximum submatrix is: " << ans;
    return 0;
}