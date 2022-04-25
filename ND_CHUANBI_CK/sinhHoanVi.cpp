#include <iostream>

using namespace std;

void k_permutation(int A[], int n, int k, bool check[], int ans[], int id)
{
    if (id == k)
    {
        for (int i = 0; i < k; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
        if (!check[i])
        {
            ans[id] = A[i];
            check[i] = 1;
            k_permutation(A, n, k, check, ans, id + 1);
            check[i] = 0;
        }
}

int main()
{
    int a[3] = {4, 5, 1};
    int ans[2] = {};
    bool check[3] = {};
    int n = 3, k = 2;

    k_permutation(a, n, k, check, ans, 0);
    return 0;
}