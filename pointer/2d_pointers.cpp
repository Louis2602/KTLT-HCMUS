#include <iostream>
#include <ctime>
using namespace std;

void input(int *a)
{
    int *p;
    p = (int *)a;
    for (int i = 0; i < 9; i++)
        p[i] = rand() % 10;
}
void output(int *ptr)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << *((int *)ptr + 3 * i + j) << " ";
        cout << '\n';
    }
}
int main()
{
    srand(time(0));
    int a[3][3];
    int *p;
    p = (int *)a;
    input((int *)a);
    output((int *)a);
    return 0;
}