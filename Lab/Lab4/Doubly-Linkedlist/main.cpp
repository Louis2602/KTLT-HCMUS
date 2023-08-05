#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *next;
    Node *prev;
};

struct List
{
    Node *head;
    Node *tail;
};

Node *createNode(int data)
{
    Node *p = new Node;
    p->key = data;
    p->next = p->prev = NULL;
    return p;
}

List createList(Node *p)
{
    List L;
    L.head = L.tail = p;
    return L;
}

void initList(List &L)
{
    L.head = L.tail = NULL;
}

bool addHead(List &L, int data)
{
    if (L.head == NULL)
    {
        Node *p = createNode(data);
        if (p == NULL)
            return false;
        else
        {
            L = createList(p);
            return true;
        }
    }

    Node *p = createNode(data);
    if (p == NULL)
        return false;
    else
    {
        p->next = L.head;
        L.head->prev = p;
        L.head = p;
        return true;
    }
}

bool addTail(List &L, int data)
{
    if (L.head == NULL)
    {
        Node *p = createNode(data);
        if (p == NULL)
            return false;
        else
        {
            L = createList(p);
            return true;
        }
    }

    Node *p = createNode(data);
    if (p == NULL)
        return false;
    else
    {
        p->prev = L.tail;
        L.tail->next = p;
        L.tail = p;
        return true;
    }
}

void printForward(List L)
{
    if (L.head == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    Node *p = L.head;
    while (p)
    {
        cout << p->key << " -> ";
        p = p->next;
    }
    cout << '\n';
}

void printBackward(List L)
{
    if (L.head == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    Node *p = L.tail;
    while (p)
    {
        cout << p->key << " -> ";
        p = p->prev;
    }
    cout << '\n';
}

void removeHead(List &L)
{
    if (L.head == NULL)
        return;
    if (L.head == L.tail)
    {
        Node *tmp = L.head;
        L.head = L.tail = NULL;
        delete tmp;
        return;
    }
    Node *t = L.head;
    L.head = L.head->next;
    L.head->prev = NULL;
    delete t;
}

void removeTail(List &L)
{
    if (L.head == NULL)
        return;
    if (L.head == L.tail)
    {
        Node *tmp = L.head;
        L.head = L.tail = NULL;
        delete tmp;
        return;
    }
    Node *t = L.tail;
    L.tail = L.tail->prev;
    L.tail->next = NULL;
    delete t;
}
void removeAll(List &L)
{
    if (L.head == NULL)
        return;
    Node *p = L.head;
    while (p)
    {
        p = p->next;
        removeHead(L);
    }
}

void removeBefore(List &L, int val)
{
    if (L.head == NULL)
        return;
    if (L.head == L.tail)
        return;

    Node *p = L.head->next;
    while (p && p->key != val)
        p = p->next;
    if (p == NULL)
        return;

    Node *p_ = p->prev;
    if (p_ == L.head)
    {
        removeHead(L);
        return;
    }
    p->prev = p_->prev;
    p_->prev->next = p;
    delete p_;
}
void removeAfter(List &L, int val)
{
    if (L.head == NULL)
        return;
    if (L.head == L.tail)
        return;

    Node *p = L.head->next;
    while (p && p->key != val)
        p = p->next;
    // Can't find val
    if (p == NULL)
        return;

    Node *p_ = p->next;
    if (p_ == L.tail)
    {
        removeTail(L);
        return;
    }
    p->next = p_->next;
    p_->next->prev = p;
    delete p_;
}

List reverseList(List L)
{
    List L_;
    initList(L_);
    if (L.head == NULL)
        return L;
    Node *p = L.head;
    while (p)
    {
        addHead(L_, p->key);
        p = p->next;
    }
    return L_;
}

void removeDuplicate(List &L)
{
    if (L.head == NULL)
        return;
    if (L.head == L.tail)
        return;

    Node *p = L.head;
    while (p)
    {
        Node *p_ = p->next;
        while (p_)
        {
            if (p_->key == p->key)
            {
                if (p_ == L.tail)
                {
                    removeTail(L);
                    p_ = NULL;
                }
                else
                {
                    Node *q = p_;
                    p_ = p_->next;
                    q->prev->next = p_;
                    p_->prev = q->prev;
                    delete q;
                }
            }
            else
                p_ = p_->next;
        }
        p = p->next;
    }
}

void removeDuplicate_2(List L)
{
    if (L.head == NULL)
        return;
    if (L.head == L.tail)
        return;
    List L1 = createList(createNode(L.head->key));
    Node *p = L.head->next;
    bool check;
    while (p)
    {
        Node *p_ = L1.head;
        check = false;
        while (p_)
        {
            if (p_->key == p->key)
            {
                check = true;
                break;
            }
            else
                p_ = p_->next;
        }
        if (check == false)
            addTail(L1, p->key);
        p = p->next;
    }
    L = L1;
}
void removeElement(List &L, int key)
{
    if (L.head == NULL)
        return;
    while (L.head && L.head->key == key)
        removeHead(L);
    while (L.head && L.tail->key == key)
        removeTail(L);
    if (L.head == NULL)
        return;
    Node *p = L.head->next;
    while (p)
    {
        if (p->key == key)
        {
            Node *q = p;
            p = p->next;
            q->prev->next = p;
            p->prev = q->prev;
            delete q;
        }
        else
            p = p->next;
    }
}
int main()
{
    List L;
    initList(L);
    cout << "Doubly Linked List:\n";
    for (int i = 1; i <= 10; i++)
    {
        addHead(L, 5);
    }
    for (int i = 11; i <= 20; i++)
    {
        addTail(L, 4);
    }
    for (int i = 11; i <= 20; i++)
    {
        addTail(L, 3);
    }
    printForward(L);
    printBackward(L);
    // removeAll(L);
    // cout << "Remove before value 11:\n";
    // Delete 1
    // removeBefore(L, 11);
    // printForward(L);
    // printBackward(L);

    // cout << "Remove after value 11:\n";
    // Delete 12
    // removeAfter(L, 11);
    // printForward(L);
    // printBackward(L);
    // cout << "Reverse List:\n";
    // List L_ = reverseList(L);
    // printForward(L_);

    // cout << "Remove duplicate 1:\n";
    // removeDuplicate(L);
    // printForward(L);

    // cout << "Remove duplicate 2:\n";
    // removeDuplicate_2(L);
    // printForward(L);

    cout << "Remove Element:\n";
    removeElement(L, 4);
    printForward(L);
    return 0;
}