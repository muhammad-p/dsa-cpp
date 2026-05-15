#include <iostream>
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
inline void linkPrevNode(Node *tmp)
{
    Node *a = head;
    while (a->next != nullptr)
    {
        a = a->next;
    }
    a->next = tmp;
}
void insert(int x)
{
    Node *tmp = new Node;
    tmp->next = nullptr;
    tmp->data = x;
    if (head == nullptr)
        head = tmp;
    else
        linkPrevNode(tmp);
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
    std::cout << "\n"<<std::endl;
}
void reverselist()
{
    Node *prev=nullptr;
    Node *cur=head;
    Node *nextt=cur->next;
    while(cur!=nullptr)
    {
        cur->next=prev;
        prev=cur;
        cur=nextt;
        if(cur==nullptr) break;
        nextt=cur->next;
    }
    head=prev;
    
}

int main()
{
    std::system("clear");
    std::cout<<"*****   REVERSE SINGLY LINKED LIST (ITERATIVE APPROACH)    *****\n\n";
    int n, x;
    std::cout << "how many numbers in list? :";
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "Enter number: ";
        std::cin >> x;
        // std::cout<<"\n";
        insert(x);
        Print();
    }
    
    if(head==nullptr) return 0;
    reverselist();
    std::cout<<"After reversing;"<<std::endl;
    Print();

    return 0;
}