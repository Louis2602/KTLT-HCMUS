#include <iostream>
using namespace std;

int main()
{
    char s[100];
    int n, i = 0, cnt = 0;
    cin >> n;
    while (n)
    {
        s[i++] = n % 10 + '0';
        cnt++;
        n /= 10;
        if (cnt % 3 == 0)
            s[i++] = ',';
    }
    if (s[i - 1] == ',')
        i--;
    s[i] = '\0';
    for (int k = 0; k < i / 2; k++)
        swap(s[k], s[i - k - 1]);
    cout << s;
    return 0;
}