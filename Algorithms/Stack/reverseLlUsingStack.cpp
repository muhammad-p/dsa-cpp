#include <stack>
#include <iostream>
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
Node *tail = nullptr;

inline void linkPrevNode(Node *tmp, Node *&tail) // tmp is the newly created node which is to be linked
{
    tail->next = tmp;
    tail = tmp;
}
void insert(int &x)
{
    Node *tmp = new Node;
    tmp->next = nullptr;
    tmp->data = x;
    if (head == nullptr)
    {
        head = tmp;
        tail = tmp;
    }
    else
        linkPrevNode(tmp, tail);
}
void Print()
{
    Node *tmp = head;
    std::cout << "The list is: ";
    while (tmp != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << "\n\n";
}
void reverseUsingStack(Node *temp)
{
    std::stack<Node *> s;
    while (temp != nullptr)
    {
        s.push(temp);
        temp = temp->next;
    }
    Node* top;
    while (!s.empty())
    {
        top=s.top();
        s.pop();
        if(s.empty())
            break;
        top->next = s.top();
    }
    head=tail;
    tail=top;
    tail->next = nullptr;
}
int main()
{
    head = nullptr;
    int n, x;

    std::cout << "Enter number of elements: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter integer element: ";
        std::cin >> x;
        insert(x);
        Print();
    }
    std::cout << "Reversing linked list using stack...\n";
    reverseUsingStack(head);
    Print();
    return 0;
}