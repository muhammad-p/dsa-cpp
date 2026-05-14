#include <iostream>
// Define Color Constants
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
Node *head, *tail;
void insert() // inserts at the end of the list
{
    int x;
    std::cout << GREEN << "Enter integer element: " << RESET;
    std::cin >> x;
    Node *newNode = new Node;
    newNode->data = x;
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;
        tail = newNode;
    }
}
void insertAt() // inserts at any valid index
{

    Node *newNode = new Node;
    Node *temp = head;
    int x;
    std::cout << GREEN << "Enter integer element: " << RESET;
    std::cin >> x;
    newNode->data = x;
    int index;
    std::cout << CYAN << "Note: " << RESET << "Index position starts from zero.\n";
    std::cout << GREEN << "Enter valid index: " << RESET;
    std::cin >> index;
    if (temp == nullptr) // if list is empty, only index 0 is valid
    {
        std::cout << RED << "ERROR:" << RESET << " Index out of bounds.\n";
        delete newNode;
        newNode = nullptr;
        return;
    }
    for (int i = 1; i < index; i++) // goes to the node after which newNode is to be added
    {
        if (temp == nullptr) //checking if index is valid or not
        {
            delete newNode;
            std::cout << RED << "ERROR:" << RESET << " Index out of bounds.\n";
            return;
        }
        temp = temp->next;
        if (index != 0 && temp == nullptr)//just to be extra safe
        {
            delete newNode;
            std::cout << RED << "ERROR: "<<RESET<<"Index out of bounds.\n";
            return;
        }
    }

    if (index == 0)// if newNode is to be added at the beginning of the list
    {
        newNode->next = temp;
        if (temp != nullptr)
            temp->prev = newNode;
        else
            tail = newNode;
        head = newNode;
        newNode->prev = nullptr;
    }
    else// if newNode is to be added in between or at the end of the list
    {
        newNode->next = temp->next;
        if (newNode->next != nullptr)
            newNode->next->prev = newNode;
        else
            tail = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }
}
void deleteAt()// deletes node at any valid index
{
    if (head == nullptr)
    {
        std::cout << RED << "ERROR: " << RESET << "Cannot delete from empty list";
        return;
    }
    Node *delNode = head;
    int index;
    std::cout << GREEN << "Enter valid index: " << RESET;
    std::cin >> index;

    for (int i = 0; i < index && delNode != nullptr; i++) // goes to the node which is to be deleted
    {
        delNode = delNode->next;
    }
    if (delNode == nullptr)//checking if index is valid or not
    {
        std::cout << RED << "ERROR:" << RESET << " Index out of bounds.\n";
        return;
    }
    if (delNode->next == nullptr && delNode->prev == nullptr)// if there is only one node in the list
    {
        head = nullptr;
        tail = nullptr;
        delete (delNode);
        delNode = nullptr;
        return;
    }
    if (delNode->next != nullptr)// if delNode is not the last node, then make the next node's prev point to delNode's prev
        delNode->next->prev = delNode->prev;
    else// if delNode is the last node, then make the previous node's next point to nullptr and update tail
    {
        delNode->prev->next = nullptr;
        tail = delNode->prev;
    }
    if (delNode->prev != nullptr)// if delNode is not the first node, then make the previous node's next point to delNode's next
        delNode->prev->next = delNode->next;
    else// if delNode is the first node, then make the next node's prev point to nullptr and update head
    {
        delNode->next->prev = nullptr;
        head = delNode->next;
    }
    delete delNode;
    delNode = nullptr;
}

void printList()
{
    if (head == nullptr)
    {
        std::cout << "The list is: (empty)\n";
        return;
    }
    Node *tmp = head;
    std::cout << "The list is: ";
    while (tmp != nullptr)
    {
        std::cout << YELLOW << tmp->data << RESET << " ";
        tmp = tmp->next;
    }
    std::cout << "\n\n";
}
int main()
{
#ifdef __APPLE__

    std::system("clear");
    std::system("clear");
#endif
    std::cout << CYAN << "\n==============================================\n"
              << RESET;
    std::cout << "     DOUBLY LINKED LIST IMPLEMENTATION   \n";
    std::cout << CYAN << "==============================================\n\n"
              << RESET;
    std::cout << RED << "Important: " << RESET << "Only enter integers to get the expected results.\n\n";
    std::cout << GREEN << "Enter number of elements: " << RESET;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        insert();
        printList();
        std::cout << "\n\n";
    }

    while (true)
    {
        int choice;
        std::cout << "-----------------------------\n";
        std::cout << CYAN << "INSERT AT ANY INDEX:" << RESET << " Enter 1\n"
                  << CYAN << "DELETE AT ANY INDEX:" << RESET << " Enter -1\n"
                  << CYAN << "EXIT: " << RESET << "Any other key\n";
        std::cin >> choice;
        std::cout << "-----------------------------\n";
        if (choice == 1)
            insertAt();
        else if (choice == -1)
            deleteAt();
        else
            break;

        printList();
        std::cout << "\n\n";
    }

    return 0;
}