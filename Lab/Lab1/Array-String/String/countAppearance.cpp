#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char c[100] = "Hello world";
    char s;
    cin >> s;
    int cnt = 0;
    int n = strlen(c);
    for (int i = 0; i < n; i++)
    {
        if (c[i] == s)
            cnt++;
    }
    cout << "Number of appearances of " << s << " is: " << cnt;
    return 0;
}
