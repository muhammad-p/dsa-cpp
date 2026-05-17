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
void Print(Node *temp)
{
    // Node *tmp = head;
    // std::cout << "The list is: ";
    // while (tmp != nullptr)
    // {
    //     std::cout << tmp->data << " ";
    //     tmp = tmp->next;
    // }
    // std::cout << "\n"
    //           << std::endl;

    std::cout << temp->data << " ";
    temp = temp->next;
    if (temp == nullptr){
        std::cout<<"\n\n";
        return;}
    Print(temp);
}
void reverselist(Node *prev, Node *cur, Node *nextt)
{
    cur->next = prev;
    prev = cur;
    cur = nextt;
    if (cur == nullptr)
    {
        head = prev;
        return;
    }
    nextt = cur->next;
    reverselist(prev, cur, nextt);
}

int main()
{
#if defined(__APPLE__) || defined(__linux__)
    std::system("clear");
#elif defined(_WIN32) || defined(WIN32)
    std::system("cls");
#endif
    std::cout << "*****   REVERSE SINGLY LINKED LIST (RECURSIVE APPROACH)   *****\n\n";
    int n, x;
    std::cout << "how many numbers in list? :";
    std::cin >> n;
    std::cout<<" \n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter number: ";
        std::cin >> x;
        // std::cout<<"\n";
        insert(x);

        Node *temp = head;
        std::cout << "The list is: ";
        Print(temp);
        std::cout << "\n\n";
    }

    if (head == nullptr)
        return 0;
    Node *prev = nullptr;
    Node *cur = head;
    Node *nextt = cur->next;

    reverselist(prev, cur, nextt);
    std::cout << "After reversing, the list is: ";
    Node *temp = head;
    Print(temp);

    return 0;
}