#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    ifstream in;
    in.open("input2.txt");
    char c;
    map<char, int> cnt;
    while (in.get(c))
        cnt[c]++;
    for (auto x : cnt)
        cout << x.first << " appears " << x.second << " times.\n";
    in.close();
    return 0;
}