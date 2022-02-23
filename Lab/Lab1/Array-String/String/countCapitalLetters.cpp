#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char c[100] = "Hello, my nAme is Tran Tung Lam"; // 4
    int cnt = 0;
    int n = strlen(c);
    for (int i = 0; i < n; i++)
    {
        if (c[i] >= 'A' && c[i] <= 'Z')
            cnt++;
    }
    cout << "Number of capital letters is: " << cnt;
    return 0;
}