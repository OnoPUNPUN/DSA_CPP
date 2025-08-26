#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    int top;
    int capacity;
    T *arr;

    void resize()
    {
        int newCapacity = capacity * 2;
        T *newArr = new T[newCapacity];
        for (int i = 0; i < top; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    Stack(int size = 2)
    {
        capacity = size;
        arr = new T[capacity];
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

    void push(T item)
    {
        if (top == capacity)
        {
            resize();
        }
        arr[top++] = item;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "❌ Stack Underflow! Nothing to pop." << endl;
            return;
        }
        top--;
    }

    T topElement()
    {
        if (isEmpty())
        {
            throw runtime_error("❌ Stack is empty!");
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

    int size()
    {
        return top;
    }

    int getCapacity()
    {
        return capacity;
    }
};

int main()
{
    Stack<int> s;
    for (int i = 1; i <= 10; i++)
    {
        s.push(i);
        cout << "Pushed: " << i
             << " | Size: " << s.size()
             << " | Capacity: " << s.getCapacity() << endl;
    }
    s.printStack();
    cout << "Top element: " << s.topElement() << endl;
    return 0;
}