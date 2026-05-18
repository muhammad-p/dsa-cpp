#include <iostream>
struct Node
{
    int data;
    Node *next;
};
Node *head, *tail;
void insert(int x)
{
    Node *newNode = new Node;
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
}
bool cycleDetection(Node *temp)
{
    Node *slow = temp;
    Node *fast = temp;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
void clearList()
{
    Node *cur = head;
    while (cur != nullptr)
    {

        Node *temp = cur->next;
        delete cur;
        cur = temp;
    }
    head = nullptr;
    tail = nullptr;
}
int main()
{
#ifdef __APPLE__
    std::system("clear");
    std::system("clear");
#endif
    std::cout << "=============================================================\n";
    std::cout << "RUNNING AUTOMATED TESTS FOR FLOYD'S CYCLE DETECTION ALGORITHM\n";
    std::cout << "=============================================================\n";

    // --------------------------------------------------
    // TEST CASE 1: Empty List
    // --------------------------------------------------
    std::cout << "Test 1 (Empty List): ";
    if (cycleDetection(head) == false)
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    // --------------------------------------------------
    // TEST CASE 2: Single Element (No Cycle)
    // --------------------------------------------------
    insert(10);
    std::cout << "Test 2 (Single Element, No Cycle): ";
    if (cycleDetection(head) == false)
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    clearList(); // Reset for next test

    // --------------------------------------------------
    // TEST CASE 3: Normal Linear List (No Cycle)
    // --------------------------------------------------
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    std::cout << "Test 3 (Linear List, No Cycle): ";
    if (cycleDetection(head) == false)
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    clearList();

    // --------------------------------------------------
    // TEST CASE 4: Cyclic List (Perfect Circle)
    // --------------------------------------------------
    insert(1);
    insert(2);
    insert(3);
    tail->next = head; // Manually create a cycle back to head (1->2->3->1)

    std::cout << "Test 4 (Perfect Circle Cycle): ";
    if (cycleDetection(head) == true)
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    
    tail->next = nullptr;
    clearList();

    // --------------------------------------------------
    // TEST CASE 5: Rho-Shaped Cycle (Lasso)
    // --------------------------------------------------
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    // Create a cycle from 50 back to 30 (10 -> 20 -> 30 -> 40 -> 50 -> 30)
    Node *loopTarget = head->next->next; // Points to 30
    tail->next = loopTarget;

    std::cout << "Test 5 (Rho-Shaped Cycle): ";
    if (cycleDetection(head) == true)
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    tail->next = nullptr; // Break cycle before exiting
    clearList();
    std::cout << "\n\n";

    return 0;
}