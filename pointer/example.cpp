#include <iostream>
using namespace std;

int main()
{
    int a = 3;
    int *ptr = &a;
    cout << "Address of a  through a ptr is: " << ptr << '\n';
    cout << "Address of a is: " << &a << '\n';
    cout << "Value of a is: " << *ptr << '\n';
    return 0;
}