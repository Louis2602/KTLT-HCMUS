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
    p->next = NULL;
    return p;
}
void addTail(Node *&head, int data)
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
bool checkIncrease(Node *h)
{

    if (h->next->next != NULL)
    {
        if (h->next->data - h->data != h->next->next->data - h->next->data)
            return false;
        else
            return checkIncrease(h->next);
    }
    return true;
}
int main()
{
    Node *head = NULL;
    cout << "List: ";
    addTail(head, 8);
    addTail(head, 11);
    addTail(head, 14);
    addTail(head, 17);
    addTail(head, 20);
    addTail(head, 23);
    print(head);
    if (checkIncrease(head))
        cout << "True";
    else
        cout << "False";
    return 0;
}
