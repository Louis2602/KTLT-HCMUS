#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *addHead(Node *&pHead, int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->next = pHead;
    pHead = tmp;
    return pHead;
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
void removeBefore(Node *&pHead, int val)
{
    if (pHead == NULL)
        return;
    Node *tmp = new Node();
    while (pHead->data != val)
    {
        tmp = pHead;
        pHead = pHead->next;
    }
    delete tmp;
}
int main()
{
    Node *head = NULL;
    addHead(head, 1);
    addHead(head, 3);
    addHead(head, 2);
    addHead(head, 5);
    addHead(head, 4);
    print(head);
    int val;
    cout << "Enter a value: ";
    cin >> val;
    cout << "Your linked list after remove the value before " << val << " is:\n";
    removeBefore(head, val);
    print(head);
    return 0;
}
