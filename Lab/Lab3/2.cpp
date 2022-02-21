#include <iostream>
using namespace std;
int *sum(int *a, int *b)
{
    static int ans = (*a) + (*b);
    return &ans;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int *ans;
    ans = sum(&a, &b);
    cout << *ans;
    return 0;
}