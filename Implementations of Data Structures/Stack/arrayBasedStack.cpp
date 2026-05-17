//#pragma once
#include <iostream>

template <typename T>
class Stack
{
private:
    int topIndex;
    int capacity;
    T *arr;
    void handleOverflow()
    {
        int newCapacity = 2 * capacity;
        T *newArr = new T[newCapacity];
        for (int i = 0; i < capacity; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

    void deleteExtraCapacity()
    {
        if(capacity<=10) return;
        int newCapacity = capacity / 2;
        T *newArr = new T[newCapacity];
        for (int i = 0; i <= topIndex; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }
public:
    Stack(int cap = 100) : topIndex(-1), capacity(cap)
    {
        arr = new T[capacity];
    }

    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;
    ~Stack()
    {
        delete[] arr;
    }
    int size() const
    {
        return topIndex + 1;
    }

    void push(T x)
    {
        if (topIndex >= capacity - 1) // handles overflow
        {
            handleOverflow();
        }
        arr[++topIndex] = x;
    }
    void pop()
    {
        if (topIndex == -1)
        {
            std::cerr << "ERROR: Cannot pop from an empty stack.\n";
            return;
        }
        topIndex = topIndex - 1;
        if (size() < 0.25 * capacity)
            deleteExtraCapacity();
    }
    bool isEmpty() const
    {
        return topIndex == -1;
    }
    T top() const
    {
        if (topIndex == -1)
        {
            std::cerr << "Stack is empty.";
            return T{}; // Return default value of T
        }
        return arr[topIndex];
    }
    void display() const
    {
        if (isEmpty())
        {
            std::cout << "The stack is empty.\n\n";
            return;
        }
        std::cout << "The stack is : top-> ";
        for (int i = topIndex; i >= 0; i--)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n\n";
    }
};
int main()
{
    Stack<int> s1;
    s1.push(5);
    s1.display();
    s1.push(4);
    s1.push(3);

    std::cout<<"The stack has "<<s1.size()<<" elements\n\n";

    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();

    //Stack <int> s2(s1);//compiler restricting copy as the copy constructor is deleted.


    return 0;
}
