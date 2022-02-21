#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    float delta = b * b - 4 * a * c;
    if (delta > 0)
        cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << "\nx2 = " << (-b - sqrt(delta)) / (2 * a) << '\n';
    else if (delta == 0)
        cout << "x1 = x2 = " << -b / (2 * a) << '\n';
    else
        cout << "No solutions" << '\n';
    return 0;
}
