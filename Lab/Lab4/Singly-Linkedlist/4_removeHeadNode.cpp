#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void removeHead(Node *&pHead)
{
    if (pHead == NULL)
        return;
    Node *tmp = pHead;
    pHead = pHead->next;

    delete tmp;
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
    removeHead(head);
    print(head);

    return 0;
}