#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *Insert(Node *&head, int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return head;
}

void Print(Node *head)
{
    Node *p = head;
    // cout << "The linked list is: ";
    // while (p != NULL)
    // {
    //     cout << p->data << "-> ";
    //     p = p->next;
    // }
    if (p == NULL)
        return;
    Print(p->next);
    cout << p->data << "-> ";
    delete p;
}

int main()
{
    Node *head = NULL;
    Insert(head, 3);
    Insert(head, 1);
    Insert(head, 7);
    Insert(head, 2);
    Insert(head, 9);
    Print(head);

    delete head;
    return 0;
}
