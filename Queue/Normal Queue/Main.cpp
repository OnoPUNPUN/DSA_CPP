#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front_index;
    int rear_index;
    int capacity;

public:
    // Constructor
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front_index = -1;
        rear_index = -1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Check if empty
    bool isEmpty() const {
        return (front_index == -1 && rear_index == -1);
    }

    // Check if full
    bool isFull() const {
        return (rear_index == capacity - 1);
    }

    // Add element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front_index = 0;
        }
        arr[++rear_index] = value;
    }

    // Remove element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front_index] << endl;

        if (front_index == rear_index) {
            front_index = rear_index = -1; // reset when empty
        } else {
            front_index++;
        }
    }

    // Peek front
    int front() const {
        return isEmpty() ? -1 : arr[front_index];
    }

    // Peek rear
    int rear() const {
        return isEmpty() ? -1 : arr[rear_index];
    }

    // Display elements
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front_index; i <= rear_index; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();
    cout << "Front: " << q.front() << "  Rear: " << q.rear() << endl;

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.display();
    cout << "Front: " << q.front() << "  Rear: " << q.rear() << endl;

    return 0;
}
