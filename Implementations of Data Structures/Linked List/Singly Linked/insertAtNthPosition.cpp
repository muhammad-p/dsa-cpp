#include <iostream>
class Node
{
public:
    static Node *head;
    int data;
    Node *next;
    static void insert(int x, int index)
    {
        Node *newnode = new Node;
        // bool proceed = validateIndex(index, newnode);
        // if (proceed == 0)
        //     return;
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
        std::cout << "The list is: ";
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    // static bool validateIndex(int index, Node *newnode)
    // {
    //     Node *temp = head;
    //     for (int i = 1; i < index; i++)
    //     {
    //         temp = temp->next;
    //         if (temp == nullptr)
    //         {
    //             std::cout << "Invalid index. Destructing current node.";
    //             delete newnode;
    //             newnode = nullptr;
    //             return false;
    //         }
    //     }
    //     delete temp;
        
    //     return true;
        
    // }
};
Node *Node::head = nullptr;
int main()
{
    Node::head = nullptr;
    int n, x, index;
    std::cout << "How many elements you want to enter into the linked list? : ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element : ";
        std::cin >> x;
        std::cout << "Enter index position : \n (fill in correct value( e.g cannot fill in 3rd index if second is empty)\n Also, remember that index position starts from zero. \n";
        std::cin >> index;
        Node::insert(x, index);
        Node::print();
    }

    return 0;
}