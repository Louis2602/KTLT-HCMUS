#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void removeTail(Node *&pHead)
{
    // empty linked list
    if (pHead == NULL)
        return;
    // linked list has 1 node
    if (pHead->next == NULL)
    {
        delete pHead;
        return;
    }
    Node *second_last = pHead;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    delete second_last->next;
    second_last->next = NULL;
}
void addHead(Node *&pHead, int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->next = pHead;
    pHead = tmp;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << '\n';
}
int main()
{
    Node *head = NULL;
    addHead(head, 5);
    addHead(head, 3);
    addHead(head, 2);
    addHead(head, 7);
    addHead(head, 4);
    addHead(head, 1);
    print(head);
    removeTail(head);
    print(head);

    return 0;
}