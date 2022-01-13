#include <iostream>
#include <iomanip>
using namespace std;
void draw()
{
    int h;
    cin >> h;
    while (h % 2 == 0)
    {
        cout << "Error! Enter again: ";
        cin >> h;
    }
    for (int i = 0; i < h; ++i)
    {
        cout << setw(h - i);
        for (int j = 1; j <= 2 * i + 1; ++j)
        {
            if (j % 2 == 0)
                cout << " ";
            else
                cout << char(i + 65);
        }
        cout << '\n';
    }
}
void checkTriangle()
{
    float a, b, c;
    cin >> a >> b >> c;
    bool isRight = false;
    bool isIso = false;
    bool isEqui = false;
    if ((a + b <= c || b + c <= a || c + a <= b) || (a <= 0 || b <= 0 || c <= 0))
    {
        cout << "not triangle";
        return;
    }
    if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b)
    {
        cout << "right triangle" << endl;
        isRight = true;
    }
    if (a == b && b == c && c == a)
    {
        cout << "equilateral triangle" << endl;
        isEqui = true;
    }
    if ((a == b || b == c || a == c) && !isEqui)
    {
        cout << "isosceles triangle" << endl;
        isIso = true;
    }
    if (isRight && isIso)
        cout << "isosceles right triangle" << endl;
    if (!isIso && !isRight && !isEqui)
        cout << "scalene triangle" << endl;
}
int main()
{
    checkTriangle();
    draw();
    return 0;
}