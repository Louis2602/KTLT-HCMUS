#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int j = 0, tmp = 0;
    bool isDot = false;
    for (int i = n - 1; i >= 0; i--)
    {
        j++;
        tmp++;
        if (s[i] == '.')
        {
            isDot = true;
            j = 0;
        }
        if (j % 3 == 0 && j > 0 && isDot)
            s.insert(s.begin() + n - tmp, ',');
    }
    s.insert(s.begin(), '$');
    cout << s;
    return 0;
}