#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *p = new Node;
    p->data = data;
    p->next = nullptr;
    return p;
}
void enqueue(Node *&head, int data)
{
    Node *p = createNode(data);
    if (head == nullptr)
    {
        head = p;
        return;
    }
    Node *t = head;
    while (t->next != nullptr)
        t = t->next;
    t->next = p;
}

void dequeue(Node *&head)
{
    if (head == nullptr)
        return;
    Node *p = head;
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
    return head == nullptr;
}
int main()
{
    Node *head = nullptr;
    int n;
    cout << "Nhap n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
        enqueue(head, i);
    print(head);
    dequeue(head);
    dequeue(head);
    dequeue(head);
    dequeue(head);
    dequeue(head);
    print(head);
    if (isEmpty(head))
        cout << "Stack is empty";
    else
        cout << "Stack is not empty";
    return 0;
}
