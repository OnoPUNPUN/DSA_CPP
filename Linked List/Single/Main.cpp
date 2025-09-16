#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertEnd(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }

    cur->next = newNode;
}

void insertFirst(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAfter(Node *head, int targetValue, int newValue)
{
    Node *cur = head;
    while (cur != nullptr && cur->data != targetValue)
    {
        cur = cur->next;
    }

    if (cur == nullptr)
    {
        cout << "Value " << targetValue << " not found!\n";
        return;
    }

    Node *newNode = new Node;
    newNode->data = newValue;
    newNode->next = cur->next;
    cur->next = newNode;
}

void deleteFirst(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List empty\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteLast(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List empty\n";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *cur = head;
    while (cur->next->next != nullptr)
    {
        cur = cur->next;
    }

    delete cur->next;
    cur->next = nullptr;
}

void deleteAfter(Node *&head, int targetValue)
{
    if (head == nullptr)
    {
        cout << "List empty\n";
        return;
    }

    Node *cur = head;
    while (cur != nullptr && cur->data != targetValue)
    {
        cur = cur->next;
    }

    if (cur == nullptr)
    {
        cout << "Value " << targetValue << " not found!\n";
        return;
    }

    if (cur->next == nullptr)
    {
        cout << "No node exists after " << targetValue << "\n";
        return;
    }

    Node *target = cur->next;
    cur->next = target->next;
    delete target;
    cout << "Deleted node after " << targetValue << "\n";
}

void printList(Node *head)
{
    if (head == nullptr)
    {
        cout << "List empty\n";
        return;
    }

    Node *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void destroyList(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *head = nullptr;
    insertFirst(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Initial list: ";
    printList(head);

    insertFirst(head, 60);
    insertAfter(head, 20, 80);

    cout << "2nd list: ";
    printList(head);

    deleteFirst(head);
    cout << "After deleting first: ";
    printList(head);

    deleteLast(head);
    cout << "After deleting last: ";
    printList(head);

    deleteAfter(head, 80);
    cout << "After deleting the node after 80: ";
    printList(head);

    destroyList(head);
    return 0;
}
