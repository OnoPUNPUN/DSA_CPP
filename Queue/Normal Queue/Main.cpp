#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front_index, rear_index, capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front_index = 0;
        rear_index = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return rear_index < front_index;
    }

    bool isFull() {
        return rear_index == capacity - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[++rear_index] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front_index++] << endl;
    }

    int front() {
        return isEmpty() ? -1 : arr[front_index];
    }

    int rear() {
        return isEmpty() ? -1 : arr[rear_index];
    }

    void display() {
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

    return 0;
}
