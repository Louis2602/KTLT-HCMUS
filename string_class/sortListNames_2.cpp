#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    char a[5][20] = {"Phan Van Duc", "Tran Tien Duc", "Nguyen Ngoc Hai", "Do Mai Huy", "Lam Thieu Huy"};
    int n = sizeof(a) / sizeof(a[0]);
    char t[5][20];
    char *p, *q;
    for (int i = 0; i < n; i++)
    {
        int j = strlen(a[i]);
        while (a[i][j] != ' ')
            j--;
        p = &a[i][j + 1];
        a[i][j] = '\0';
        q = a[i];
        strcpy(t[i], p);
        int k = strlen(t[i]);
        t[i][k] = ' ';
        t[i][k + 1] = '\0';
        strcat(t[i], q);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(t[i], t[j]) > 0)
            {
                char tmp[20];
                strcpy(tmp, t[i]);
                strcpy(t[i], t[j]);
                strcpy(t[j], tmp);
            }
        }
    }
    char ans[5][20];
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (t[i][j] != ' ')
            j++;
        p = &t[i][j + 1];
        t[i][j] = '\0';
        q = t[i];
        strcpy(ans[i], p);
        int k = strlen(ans[i]);
        ans[i][k] = ' ';
        ans[i][k + 1] = '\0';
        strcat(ans[i], q);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';

    return 0;
}