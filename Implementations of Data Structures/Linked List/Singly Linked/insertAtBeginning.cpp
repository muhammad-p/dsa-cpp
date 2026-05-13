 #include <iostream>
struct Node
{
    int data;
    Node *next;
};
Node *head;
void InsertAtBeg(int &x)
{
    Node* tmp=new Node;
    tmp->data=x;
    tmp->next=head;
    head=tmp;

}
void Print() 
{
    Node* temp=head;
    std::cout<<"Linked List is: ";
    while(temp!=nullptr)
    {
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}
int main()
{
    head = nullptr;
    int n,x;

    std::cout << "How many numbers? ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter Number : ";
        std::cin >> x;
        InsertAtBeg(x);
        Print();
    }

    return 0;
}