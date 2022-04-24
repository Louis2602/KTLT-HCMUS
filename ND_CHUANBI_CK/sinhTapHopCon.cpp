#include <iostream>
using namespace std;

void Try(int i, int m, int *s, int n)
{
    int z;
    for (z = s[i - 1] + 1; z <= n; z++)
    {
        s[i] = z;
        if (i == m)
        {
            int k;
            for (k = 1; k <= m; k++)
                cout << s[k];
            cout << " ";
        }
        else
            Try(i + 1, m, s, n);
    }
}
int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int *s = new int[n + 1];
    s[0] = 0;
    int i;
    for (i = 0; i <= n; i++)
    {
        cout << "Cac tap con " << i << " phan tu la:\n";
        Try(1, i, s, n);
        cout << endl;
    }
    delete s;
    return 0;
}