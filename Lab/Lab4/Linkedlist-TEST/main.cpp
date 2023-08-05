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

void addHead(Node *&pHead, int data)
{
    if (pHead == NULL)
    {
        pHead = createNode(data);
        return;
    }
    Node *p = createNode(data); // Node can them vao dau danh sach lien ket
    p->next = pHead;
    pHead = p;
}
void addTail(Node *&pHead, int data)
{
    if (pHead == NULL)
    {
        pHead = createNode(data);
        return;
    }
    Node *p = createNode(data);
    Node *p_ = pHead;
    while (p_->next != NULL)
    {
        p_ = p_->next;
    }
    p_->next = p;
}
// bool addHeadBoolean(Node *&pHead, int data)
// {
//     if (pHead == NULL)
//     {
//         pHead = createNode(data);
//         if (pHead == NULL)
//             return false;
//         else
//             return true;
//     }
//     Node *p = createNode(data); // Node can them vao dau danh sach lien ket
//     if (pHead == NULL)
//         return false;
//     else
//     {
//         p->next = pHead;
//         pHead = p;
//         return true;
//     }
// }
void removeHead(Node *&pHead)
{
    if (pHead == NULL)
        return;
    Node *p = pHead;
    pHead = p->next;
    delete p;
}
void removeTail(Node *&pHead)
{
    if (pHead == NULL)
        return;
    Node *p = pHead;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    Node *p_ = p->next;
    p->next = NULL;
    delete p_;
}
void printList(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << '\n';
}
int main()
{
    Node *head = NULL;
    // addHead(head, 3);
    // addHead(head, 5);
    // addHead(head, 4);
    // addHead(head, 1);
    addTail(head, 3);
    addTail(head, 5);
    addTail(head, 4);
    addTail(head, 1);
    printList(head);
    removeTail(head);
    printList(head);
    return 0;
}