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
    int a[6] = {1, 2, 3, 4, 5, 6};
    int ans[7] = {};
    bool check[10] = {};
    int n = 6, k = 3;

    k_permutation(a, n, k, check, ans, 0);
    return 0;
}