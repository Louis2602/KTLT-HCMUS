#include <iostream>
using namespace std;

int main()
{
    static int k;
    cout << k << '\n'; // 0

    static int s{1};
    ++s;
    cout << s;
    return 0;
}