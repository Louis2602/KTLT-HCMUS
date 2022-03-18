#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    char a[5][20] = {"Phan Van Duc", "Tran Tien Duc", "Nguyen Ngoc Hai", "Do Mai Huy", "Lam Thieu Huy"};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        while (a[i][strlen(a[i]) - 1] != ' ')
        {
            char tmp = a[i][strlen(a[i]) - 1];
            // Shift Right
            for (int j = strlen(a[i]) - 1; j > 0; j--)
                a[i][j] = a[i][j - 1];
            a[i][0] = tmp;
            ++cnt;
        }
        for (int k = strlen(a[i]) - 1; k > cnt; k--)
            a[i][k] = a[i][k - 1];
        a[i][cnt] = ' ';
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[i], a[j]) > 0)
            {
                char tmp[20];
                strcpy(tmp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], tmp);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        while (a[i][0] != ' ')
        {
            char tmp = a[i][0];
            // Shift Left
            for (int j = 0; j < strlen(a[i]) - 1; j++)
                a[i][j] = a[i][j + 1];
            a[i][strlen(a[i]) - 1] = tmp;
            ++cnt;
        }
        for (int k = 0; k < strlen(a[i]) - cnt - 1; k++)
            a[i][k] = a[i][k + 1];
        a[i][strlen(a[i]) - 1 - cnt] = ' ';
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << '\n';
    return 0;
}