#include <iostream>
using namespace std;

int x[31], t[31], n;

void init()
{
    cout << "Nhap n: ";
    cin >> n;
    x[0] = 1;
    t[0] = 0;
}
void print(int k)
{
    cout << n << " = ";
    for (int i = 1; i < k; i++)
        cout << x[i] << " + ";
    cout << x[k];
    cout << '\n';
}
void process(int i)
{
    for (int j = x[i - 1]; j <= ((n - t[i - 1]) / 2); j++)
    {
        x[i] = j;
        t[i] = t[i - 1] + j;
        process(i + 1);
    }
    x[i] = n - t[i - 1];
    print(i);
}
int main()
{
    init();
    process(1);
    return 0;
}