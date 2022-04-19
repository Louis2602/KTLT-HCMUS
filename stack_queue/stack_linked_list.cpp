#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *p = new Node();
    p->data = data;
    p->next = nullptr;
    return p;
}

void push(Node *&head, int data)
{
    Node *p = createNode(data);
    if (head == nullptr)
    {
        head = p;
        return;
    }
    p->next = head;
    head = p;
}

void pop(Node *&head)
{
    Node *p = head;
    if (head == nullptr)
        return;
    head = p->next;
    delete p;
}
void print(Node *head)
{
    Node *p = head;
    while (p)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << '\n';
}
bool isEmpty(Node *head)
{
    if (head == nullptr)
        return true;
    return false;
}
int main()
{
    Node *head = nullptr;
    int n;
    cout << "Nhap n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
        push(head, i);
    print(head);
    pop(head);
    print(head);
    pop(head);
    pop(head);
    pop(head);
    pop(head);
    print(head);
    if (isEmpty(head))
        cout << "Stack is empty";
    else
        cout << "Stack is not empty";
    return 0;
}