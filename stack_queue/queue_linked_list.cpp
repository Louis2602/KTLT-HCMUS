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
    p->next = NULL;
    return p;
}
void enqueue(Node *&head, int data)
{
    Node *p = createNode(data);
    if (head == NULL)
    {
        head = p;
        return;
    }
    Node *t = head;
    while (t->next != NULL)
        t = t->next;
    t->next = p;
    p->next = NULL;
}

void dequeue(Node *&head)
{
    if (head == NULL)
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
    if (head == NULL)
        return true;
    return false;
}
int main()
{
    Node *head = NULL;
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