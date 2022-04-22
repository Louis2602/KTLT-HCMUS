#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head = NULL;
};

Node *createNode(int data)
{
    Node *p = new Node();
    p->data = data;
    p->next = NULL;
    return p;
}
void addTail(List &ls, int data)
{
    Node *p = createNode(data);
    if (ls.head == NULL)
    {
        ls.head = p;
        return;
    }
    Node *t = ls.head;
    while (t->next != NULL)
        t = t->next;
    t->next = p;
}
void print(List ls)
{
    Node *p = ls.head;
    while (p)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << '\n';
}
int Count(List ls)
{
    Node *p = ls.head;
    int cnt = 0;
    if (ls.head == NULL)
        return 0;
    while (p->next->next != NULL)
    {
        if (p->data - p->next->data == p->next->next->data)
        {
            cnt++;
            cout << p->data << " " << p->next->data << " " << p->next->next->data << '\n';
        }
        p = p->next;
    }
    return cnt;
}
int main()
{
    List ls;
    cout << "List: ";
    addTail(ls, 12);
    addTail(ls, 10);
    addTail(ls, 2);
    addTail(ls, 8);
    addTail(ls, 5);
    addTail(ls, 4);
    addTail(ls, 3);
    addTail(ls, 1);
    print(ls);
    cout << Count(ls);
    return 0;
}
