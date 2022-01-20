#include <iostream>
using namespace std;

int main()
{
    int m[3][3] = {
        {3, 1, 5},
        {2, 6, 9},
        {8, 7, 4}};
    int n = 3;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                for (int l = 0; l < n; ++l)
                    if (m[i][j] < m[k][l])
                        swap(m[i][j], m[k][l]);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << m[i][j] << " ";
        cout << '\n';
    }

    return 0;
}