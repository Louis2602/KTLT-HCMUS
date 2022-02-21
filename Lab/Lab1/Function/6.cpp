#include <iostream>
using namespace std;

int countInteger(int N, int k)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % k == 0)
            cnt++;
    }
    return cnt;
}
int main()
{
    int N, k;
    cin >> N;
    k = 3;
    int ans = countInteger(N, k);
    cout << "Number of integer that is smaller than " << N << " and divisible by " << k << " is: " << ans << endl;
    return 0;
}