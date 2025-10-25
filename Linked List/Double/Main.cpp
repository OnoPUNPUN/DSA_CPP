#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Create a new node
Node* createNode(int item, Node* next = nullptr, Node* prev = nullptr) {
    Node* newNode = new Node;

    if (newNode == nullptr) {
        cout << "Error! Can't create the node\n";
        return nullptr;
    }

    newNode->data = item;
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
}

// Insert at the beginning
Node* createFirst(Node* head, int item) {
    Node* newNode = createNode(item, head, nullptr);
    if (head != nullptr) {
        head->prev = newNode;
    }
    return newNode; // new head
}

// Insert at the end
Node* createLast(Node* head, int item) {
    Node* newNode = createNode(item);

    if (head == nullptr) {
        return newNode;
    }

    Node* currentNode = head;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    newNode->prev = currentNode;

    return head;
}

// Insert after any given node
void insertAtAny(Node* node, int item) {
    if (node == nullptr) return;

    Node* newNode = createNode(item, node->next, node);

    if (node->next != nullptr) {
        node->next->prev = newNode;
    }
    node->next = newNode;
}

// Remove first node
Node* removeFirst(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
    return head;
}

// Remove last node
Node* removeLast(Node* head) {
    if (head == nullptr) return nullptr;

    if (head->next == nullptr) { // only one node
        delete head;
        return nullptr;
    }

    Node* currentNode = head;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }

    currentNode->prev->next = nullptr;
    delete currentNode;

    return head;
}

// Remove a given node
Node* removeAtAny(Node* head, Node* node) {
    if (head == nullptr || node == nullptr) return head;

    if (node == head) {
        return removeFirst(head);
    }

    if (node->next != nullptr) {
        node->next->prev = node->prev;
    }
    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }

    delete node;
    return head;
}

// Print list forward
void print(Node* head) {
    Node* currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << "\n";
}

// Print list backward
void printReverse(Node* head) {
    if (head == nullptr) return;

    Node* currentNode = head;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }

    while (currentNode != nullptr) {
        cout << currentNode->data << " ";
        currentNode = currentNode->prev;
    }
    cout << "\n";
}
