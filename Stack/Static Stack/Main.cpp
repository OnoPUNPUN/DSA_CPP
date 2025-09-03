#include <iostream>
using namespace std;

template <typename T>
struct Stack
{
    int top;
    int maxSize;
    T *arr;

    Stack(int size)
    {
        maxSize = size;
        arr = new T[maxSize];
        top = 0;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return (top == 0);
    }

    bool isFull()
    {
        return (top == maxSize);
    }

    void push(T item)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << item << endl;
            return;
        }
        arr[top++] = item;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        top--;
    }

    T topElement()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty! No top element.");
        }
        return arr[top - 1];
    }

    void printStack()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack<int> intStack(5);
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.printStack();
    cout << "Top element: " << intStack.topElement() << endl;
    intStack.pop();
    intStack.printStack();

    cout << "---------------------------" << endl;

    Stack<string> strStack(3);
    strStack.push("Hello");
    strStack.push("World");
    strStack.printStack();
    cout << "Top element: " << strStack.topElement() << endl;

    return 0;
}