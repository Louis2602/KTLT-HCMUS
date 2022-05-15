#include <iostream>
#include <string>

using namespace std;

bool q1(string s)
{
    int l = 0;
    s = ' ' + s;
    int n = s.size();
    string tmp[100];
    int k = 0;
    cout << s << endl;
    for (int i = 1; i < n; i++)
    {
        if ((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z'))
        {
            tmp[k] = s.substr(l + 1, i - 1 - l);
            l = i;
            k++;
        }
    }
    for (int i = 0; i < k; i++)
        cout << tmp[i] << '\n';
    for (int i = 1; i < k / 2; i++)
    {
        if (tmp[i] != tmp[k - i - 1])
            return 0;
    }
    return 1;
}
int main()
{
    string s;
    getline(cin, s);
    if (q1(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}