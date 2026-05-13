#include <iostream>
class Node
{
public:
    static Node *head;
    int data;
    Node *next;
    static void insert(int x, int index)
    {
        // static int counter=0;
        // bool proceed = validateIndex(counter,index);
        // if(proceed==0)
        // {
        //     return;
        // }
        // counter++;
        Node *newnode = new Node;
        
        newnode->data = x;
        newnode->next = nullptr;
        linknode(index, newnode);
    }
    static void linknode(int index, Node *newnode)
    {

        if (index == 0 || head == nullptr)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    static void print()
    {
        Node *temp = head;
        std::cout << "\n\nThe list is: ";
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n"<<std::endl;
    }
    static void deleteAt(int index)
    {
        Node *temp1 = head;
        for (int i = 1; i < index; i++)
        {
            temp1 = temp1->next;
        }
        Node *temp2 = head;
        for (int i = 1; i <= index; i++)
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        if (index == 0)
            head = temp2->next;
        delete temp2;
        temp2 = nullptr;
    }
    // inline static bool validateIndex(int &count,int &index)
    // {
    //     if(index>count)
    //     {
    //         std::cout<<"Invalid index position. Please re-enter element and valid index value.\n";
    //         return false;
    //     }
    //     else
    //         return true;

       

    // }
};
Node *Node::head = nullptr;

int main()
{
    std::system("clear");
    Node::head = nullptr;
    int n, x, index;
    std::cout<<"*****   IMPLEMENTATION OF SINGLY LINKED LIST   *****\n\n";
    std::cout<<"Note: Enter valid index to run the program as expected. (Index position starts from zero.) ";


    std::cout << "\n\nEnter number of elements to be added to the list : ";
    std::cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        std::cout << "\n\nEnter integer element : ";
        std::cin >> x;
        std::cout << "Enter index position : ";
        std::cin >> index;
        Node::insert(x, index);
        Node::print();
    }
    int choice = 1;
    while (choice == 1 || choice == -1)
    {
        std::cout << "Add node: Press -1.\nDelete node: Press 1\nExit: Any other key.\n";
        std::cin >> choice;
        if (choice != 1 && choice != -1)
            break;
        if (choice == -1)
        {
            std::cout << "Enter element : ";
            std::cin >> x;
            std::cout << "Enter index position : ";
            std::cin >> index;
            Node::insert(x, index);
            Node::print();
        }
        else if (choice == 1)
        {
            int delIndex;
            std::cout << "enter index : ";
            std::cin >> delIndex;
            Node::deleteAt(delIndex);
            std::cout << "New list is : ";
            Node::print();
        }
    }

    return 0;
}