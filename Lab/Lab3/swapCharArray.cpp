#include <iostream>
#include <cstring>

using namespace std;
void Swap(char *a, char *b)
{
    char p[3];
    strcpy(p, a);
    strcpy(a, b);
    strcpy(b, p);
}
void sort(char a[][5], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(a[i], a[j]) > 0)
                Swap(a[i], a[j]);
}
int main()
{
    char a[3][5] = {"zb", "cde", "abcd"};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}