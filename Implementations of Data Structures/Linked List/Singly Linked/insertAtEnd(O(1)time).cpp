#include <iostream>
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
Node* tail=nullptr;

inline void linkPrevNode(Node *tmp,Node* &tail) //tmp is the newly created node which is to be linked
{
    tail->next = tmp;
    tail=tmp;
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
        linkPrevNode(tmp,tail);
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
    std::cout << std::endl;
}

int main()
{
    int n, x;
    std::cout << "how many numbers in list? :";
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "Enter number: ";
        std::cin >> x;
        
        insert(x);
        Print();
    }

    return 0;
}