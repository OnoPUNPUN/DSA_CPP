#include <iostream>
#include <stdexcept>  // for runtime_error
using namespace std;

template <typename T>
class Stack {
private:
    int topIndex;
    int maxSize;
    T* arr;

public:
    // Constructor
    Stack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        topIndex = 0;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Check if empty
    bool isEmpty() const {
        return (topIndex == 0);
    }

    // Check if full
    bool isFull() const {
        return (topIndex == maxSize);
    }

    // Push element
    void push(const T& item) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << item << endl;
            return;
        }
        arr[topIndex++] = item;
    }

    // Pop element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        topIndex--;
    }

    // Get top element
    T topElement() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty! No top element.");
        }
        return arr[topIndex - 1];
    }

    // Print stack
    void printStack() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = topIndex - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        // Integer stack
        Stack<int> intStack(5);
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.printStack();
        cout << "Top element: " << intStack.topElement() << endl;
        intStack.pop();
        intStack.printStack();

        cout << "---------------------------" << endl;

        // String stack
        Stack<string> strStack(3);
        strStack.push("Hello");
        strStack.push("World");
        strStack.printStack();
        cout << "Top element: " << strStack.topElement() << endl;
    } 
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
