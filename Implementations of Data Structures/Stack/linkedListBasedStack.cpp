//#pragma once
#include <iostream>

template <typename T>
class Stack
{

    struct Node
    {
        T data;
        Node *next;
    };
    int Size;
    Node *Top;

public:
    Stack() : Top(nullptr), Size(0)
    {
    }
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;
    ~Stack()
    {
        while (!isEmpty())
            pop();
    }

    bool isEmpty() const
    {
        return Top == nullptr;
    }
    int size() const
    {
        return Size;
    }
    T top() const
    {
        if (Top == nullptr)
        {
            std::cerr << "ERROR: Stack is empty.\n";
            return T{};
        }
        return Top->data;
    }
    void pop()
    {
        if (Top == nullptr)
        {
            std::cerr << "ERROR: Cannot pop from an empty stack.\n";
            return;
        }
        Node *temp = Top;
        Top = Top->next;
        delete temp;
        Size--;
    }
    void push(T x)
    {
        Node *newNode = new Node;
        newNode->data = x;
        if (Top == nullptr)
        {
            Top = newNode;
            newNode->next = nullptr;
        }
        else
        {
            newNode->next = Top;
            Top = newNode;
        }
        Size++;
    }
    void display() const
    {
        if (isEmpty())
        {
            std::cout << "The stack is empty.\n\n";
            return;
        }
        Node *temp = Top;
        std::cout << "The stack is: top-> ";
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
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