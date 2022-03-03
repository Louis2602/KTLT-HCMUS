#include <iostream>
#include <ctime>
using namespace std;

int **generateMatrix1(int **A, int &length, int &width)
{
    srand(time(0));
    // Khoi tao mang 2 chieu
    A = new int *[width];
    for (int i = 0; i < width; i++)
    {
        // Khoi tao mang 1 chieu
        *(A + i) = new int[length];
        for (int j = 0; j < length; j++)
            *(*(A + i) + j) = rand() % 10;
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
void swapRows(int **a, int length, int width)
{
    cout << "Swap rows\n";
    for (int i = 0; i < width / 2; i++)
    {
        for (int j = 0; j < length; j++)
        {
            swap(*(*(a + i) + j), *(*(a + length - i - 1) + j));
        }
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
            cout << *(*(a + i) + j) << " ";
        cout << '\n';
    }
}
void swapColumns(int **a, int length, int width)
{
    cout << "Swap columns\n";
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length / 2; j++)
        {
            swap(*(*(a + i) + j), *(*(a + i) + length - j - 1));
        }
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
            cout << *(*(a + i) + j) << " ";
        cout << '\n';
    }
}

int main()
{
    int length, width;
    int **a;
    cout << "Enter a length: ";
    cin >> length;
    cout << "Enter a width: ";
    cin >> width;
    int **matrix_swap_rows, **matrix_swap_cols;
    matrix_swap_rows = generateMatrix1(a, length, width);
    matrix_swap_cols = generateMatrix1(a, length, width);
    swapRows(matrix_swap_rows, length, width);
    swapColumns(matrix_swap_cols, length, width);
    return 0;
}
