#include <iostream>
using namespace std;

void permutation_1(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << ", ";
        return;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            permutation_1(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}

void permutation_2(string s, string ans)
{
    if (s.size() == 0)
    {
        cout << ans << ", ";
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0, i);
        string right_substr = s.substr(i + 1);
        string rest = left_substr + right_substr;
        permutation_2(rest, ans + ch);
    }
}
int main()
{
    string s, ans;
    cin >> s;
    cout << "All the permutations:\n";
    permutation_2(s, ans);
    // permutation_1(s, 0, s.size() - 1);
    return 0;
}
