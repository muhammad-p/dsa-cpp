#include <iostream>
const char *RESET = "\033[0m";
const char *RED = "\033[31m";
const char *GREEN = "\033[32m";
const char *YELLOW = "\033[33m";
const char *CYAN = "\033[36m";
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
Node *head = nullptr;
Node *tail = nullptr;
void insert(int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;
        tail = newNode;
    }
}
void reverseList()
{
    Node *cur = head;
    Node *temp = head->next;
    cur->next = nullptr;
    cur->prev = temp;
    tail = cur;
    while (temp != nullptr)
    {
        cur = temp;
        temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
    }
    head = cur;
}
void printList()
{
    Node *temp = head;
    std::cout << "The list is: ";
    while (temp != nullptr)
    {
        std::cout << YELLOW << temp->data << " ";
        temp = temp->next;
    }
    std::cout <<RESET << "\n"<<"\n\n";
}
void reversePrint()
{
    Node *temp = tail;
    std::cout << "The list printed in reverse order is: ";
    while (temp != nullptr)
    {
        std::cout << YELLOW << temp->data << " ";
        temp = temp->prev;
    }
    std::cout <<RESET << "\n"<<"\n\n";

}
int getElement()
{
    int x;
    std::cout << GREEN<<"Enter integer element: "<<RESET;
    std::cin >> x;
    std::cout<<"\n";
    return x;
}
int main()
{
#ifdef __APPLE__
    std::system("clear");
    std::system("clear");
#endif
    std::cout << CYAN << "\n==============================================\n"
              << RESET;
    std::cout << "        REVERSING DOUBLY LINKED LIST   \n";
    std::cout << CYAN << "==============================================\n\n"
              << RESET;
    std::cout<<RED<<"Important: "<<RESET<<"Only enter integer elements to run the program as expected.\n\n"<<RESET;
    int n;
    std::cout << "Enter number of elements to be added: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        insert(getElement());
        printList();
    }
    // reversePrint();
    // printList();
    reverseList();
    std::cout << CYAN<<"After reversing the list: "<<RESET<<"checking if all the pointers are set correctly, by printing in forward and reverse order\n\n";
    printList();
    reversePrint();
    return 0;
}