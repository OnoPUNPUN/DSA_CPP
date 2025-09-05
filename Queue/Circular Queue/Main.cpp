#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front_index, rear_index, capacity;

public:
    // Constructor
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front_index = -1;
        rear_index = -1;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }

    // Check if queue is empty
    bool isEmpty() const {
        return (front_index == -1);
    }

    // Check if queue is full
    bool isFull() const {
        return ((rear_index + 1) % capacity == front_index);
    }

    // Add element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Circular Queue Overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front_index = rear_index = 0;
        } else {
            rear_index = (rear_index + 1) % capacity;
        }
        arr[rear_index] = value;
    }

    // Remove element
    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front_index] << endl;

        if (front_index == rear_index) {
            front_index = rear_index = -1;  // reset
        } else {
            front_index = (front_index + 1) % capacity;
        }
    }

    // Peek front element
    int front() const {
        return isEmpty() ? -1 : arr[front_index];
    }

    // Peek rear element
    int rear() const {
        return isEmpty() ? -1 : arr[rear_index];
    }

    // Display all elements
    void display() const {
        if (isEmpty()) {
            cout << "Circular Queue is empty!" << endl;
            return;
        }
        cout << "Circular Queue: ";
        if (front_index <= rear_index) {
            for (int i = front_index; i <= rear_index; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front_index; i < capacity; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear_index; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(2);
    cq.enqueue(5);
    cq.enqueue(7);
    cq.enqueue(1);
    cq.enqueue(3);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.enqueue(12);
    cq.enqueue(11);

    cq.display();
    cout << "Front: " << cq.front() << "  Rear: " << cq.rear() << endl;

    return 0;
}
