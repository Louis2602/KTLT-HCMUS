#include <iostream>
using namespace std;

int *findMax(int *a, int n)
{
    static int max = *a;
    for (int i = 0; i < n; i++)
        if (max < *(a + i))
            max = *(a + i);
    return &max;
}

int main()
{
    int a[5] = {2, 5, 8, 1, -4};
    int n = 5;
    int *ans;
    ans = findMax(a, n);
    cout << "Max: " << *ans;
    return 0;
}