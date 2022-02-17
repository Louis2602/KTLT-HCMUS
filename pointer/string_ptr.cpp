#include <iostream>
using namespace std;

int main()
{
    string s = "Hello";
    string *ptr = &s;
    cout << "Address of s: " << ptr << '\n';
    cout << "The first letter of s: " << s[0] << '\n';
    cout << "String s using ptr: " << *ptr;
    return 0;
}