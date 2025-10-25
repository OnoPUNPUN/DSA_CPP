#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int item, Node *next)
{
    Node *newNode = new Node;

    if (newNode == nullptr)
    {
        cout << "Error Can't Make the Node";
        return;
    }

    newNode->data = item;
    newNode->next = next;
    return newNode;
}

Node *removeFirst(Node *head)
{
    if (head == nullptr)
        return;

    Node *temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node *removeAtAny(Node *head, Node *node)
{
    if (head == nullptr || node == nullptr)
    {
        return nullptr;
    }

    if (node == head)
    {
        head = head->next;
        delete node;
        return head;
    }

    Node *currentNode = head;

    while (currentNode != nullptr)
    {
        if (currentNode->next = node)
        {
            break;
        }

        currentNode = currentNode->next;
    }

    if (currentNode == nullptr)
    {
        return head;
    }

    currentNode->next = node->next;
    delete node;
    return head;
}

Node *removeLast(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *currentNode = head;

    while (currentNode->next->next != nullptr)
    {
        currentNode = currentNode->next;
    }

    delete currentNode->next;
    currentNode->next = nullptr;
    return head;
}

Node *creatFirst(Node *head, int item)
{
    Node *newNode = createNode(item, head);
    return newNode;
}

Node *createLast(Node *head, int item)
{
    Node *newNode = createNode(item, head);

    if (head == nullptr)
    {
        return newNode;
    }

    Node *currentNode = head;

    while (currentNode->next != nullptr)
    {
        currentNode = currentNode->next;
    }

    currentNode = newNode;
    return head;
}

void insertAtAny(Node *node, int item)
{
    Node *newNode = createNode(item, node->next);
    node->next = newNode;
}

void print(Node *head)
{
    Node *currentNode = head;

    while (currentNode != nullptr)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
}
