#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insertAtBeginning(int value)
    {

        Node *newNode = new Node(value);
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
    }

    void insertAtEnd(int value)
    {

        Node *newNode = new Node(value);
        newNode->next = NULL;

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int value)
    {
        Node *temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Node with value " << key << " not found.\n";
            return;
        }

        Node *newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteFromStart()
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        if (temp->prev != NULL)
            temp->prev->next = NULL;
        else
            head = NULL;

        delete temp;
    }
};

int main()
{

    DoublyLinkedList D;
    D.insertAtBeginning(4);
    D.insertAtEnd(5);
    D.insertAtEnd(7);

    D.deleteFromStart();
    D.display();

    return 0;
}