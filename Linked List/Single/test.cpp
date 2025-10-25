#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

Node* createNode(int data, Node* next) {
  Node* newNode = new Node;

  if(newNode == nullptr) {
    cout << "Error";
    exit(1);
  }

  newNode->data = data;
  newNode->next = next;

  return newNode;
}

Node* deleteFirst(Node* head) {
  if(head == nullptr) {
    return nullptr;
  }

  Node* temp = head;
  head = head->next;
  delete temp;
}

Node* deleteLast(Node* head) {
  if(head == nullptr) {
    return nullptr;
  }

  Node* currentNode = new Node;
  while(currentNode->next->next != nullptr) {
    currentNode = currentNode->next;
  }

  delete currentNode->next;
  return head;
}

Node* deleteAny(Node* head, Node* node) {
  if(head == nullptr || node == nullptr) {
    return nullptr;
  }

  if(head == node) {
    head = head->next;
    delete node;
  }

  Node* currentNode = new Node;

  while (currentNode != nullptr)
  {
    if(currentNode->next == node) {
      break;
    }
    currentNode = currentNode->next;
  }

  currentNode->next = node->next;

  delete node;
  return head;
}

