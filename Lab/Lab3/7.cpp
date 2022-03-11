#include <iostream>
using namespace std;

int *countEvens(int *a, int n)
{
    static int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 == 0)
            cnt++;
    }
    return &cnt;
}
int *genEvenSubarray(int *a, int n, int *evens)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 == 0)
        {
            *(evens + j) = *(a + i);
            j++;
        }
    }
    return evens;
}
int main()
{
    int a[9] = {3, 2, 4, 1, 10, 11, 6, 7, 20};
    int n = 9;
    int *cnt;
    cnt = countEvens(a, n);
    cout << "Number of evens in the array is: " << *cnt << '\n';
    int *evens = new int[*cnt];
    int *res = genEvenSubarray(a, n, evens);
    for (int i = 0; i < *cnt; i++)
        cout << *(res + i) << " ";
    delete[] evens;
    return 0;
}