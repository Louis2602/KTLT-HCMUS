#include <iostream>
using namespace std;

void change1(int num)
{
    num = num + 1;
}

void change2(int *num)
{
    *num = *num + 1;
}

int main()
{
    int x = 100;
    printf("Truoc khi goi phuong thuc x = %d \n", x);
    change1(x);
    printf("Sau khi goi phuong thuc tham tri x = %d \n", x);
    cout << &x << endl;
    change2(&x); // truyen tham chieu vao phuong thuc
    printf("Sau khi goi phuong thuc tham chieu x = %d \n", x);
    return 0;
}