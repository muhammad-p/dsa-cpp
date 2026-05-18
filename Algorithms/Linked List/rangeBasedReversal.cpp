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
    newNode->data = x;
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
void printList()
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << "\n\n";
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
void reverse(int l, int r)
{
    if (head == nullptr || l == 0 || l >= r || head == tail)
        return;
    Node *prev = nullptr, *cur = nullptr, *next = nullptr, *leftNode = nullptr, *rangeTail = nullptr, *temp;

    cur = head;
    for (int i = 1; i < l; i++)
    {
        leftNode = cur;
        if (cur == nullptr)
            return;
        cur = cur->next;
    }
    next = cur->next;

    temp = head;
    for (int i = 0; i < r; i++)
    {
        if (temp == nullptr)
            return;
        temp = temp->next;
    }
    rangeTail = cur;
    while (cur != temp)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        if (cur != nullptr)
            next = cur->next;
    }
    if (leftNode == nullptr)
        head = prev;
    else
        leftNode->next = prev;
    rangeTail->next = cur;
}

#include <vector>

// Helper function to check if the current list matches an expected sequence of values
bool verifyListLayout(const std::vector<int>& expected) {
    Node* tmp = head;
    for (int val : expected) {
        if (tmp == nullptr || tmp->data != val) return false;
        tmp = tmp->next;
    }
    return tmp == nullptr; // True if we reached the exact end of both
}

int main()
{
    std::cout << "====================================================\n";
    std::cout << "RUNNING AUTOMATED TESTS FOR RANGE-BASED REVERSAL    \n";
    std::cout << "====================================================\n\n";

    // -------------------------------------------------------------------------
    // TEST CASE 1: Guard Rails & Early Returns
    // -------------------------------------------------------------------------
    std::cout << "Test 1a (Empty List):\n";
    clearList();
    reverse(1, 3); 
    if (head == nullptr && tail == nullptr) {
        std::cout << "--> STATUS: PASSED\n\n";
    } else {
        std::cout << "--> STATUS: FAILED\n\n";
    }

    std::cout << "Test 1b (Single Element List):\n";
    clearList();
    insert(10);
    reverse(1, 2);
    if (verifyListLayout({10})) {
        std::cout << "--> STATUS: PASSED\n\n";
    } else {
        std::cout << "--> STATUS: FAILED\n" << "Got: "; printList();
    }

    std::cout << "Test 1c (Left index out of bounds / Zero):\n";
    clearList();
    insert(10); insert(20); insert(30);
    reverse(0, 2);
    if (verifyListLayout({10, 20, 30})) {
        std::cout << "--> STATUS: PASSED\n\n";
    } else {
        std::cout << "--> STATUS: FAILED\n" << "Got: "; printList();
    }

    std::cout << "Test 1d (Left index >= Right index):\n";
    clearList();
    insert(10); insert(20); insert(30);
    reverse(2, 2);
    if (verifyListLayout({10, 20, 30})) {
        std::cout << "--> STATUS: PASSED\n\n";
    } else {
        std::cout << "--> STATUS: FAILED\n" << "Got: "; printList();
    }


    // -------------------------------------------------------------------------
    // TEST CASE 2: Reversing from the Head Node
    // -------------------------------------------------------------------------
    std::cout << "Test 2a (Subsegment starting precisely at Head [l = 1]):\n";
    clearList();
    insert(10); insert(20); insert(30); insert(40); insert(50);
    reverse(1, 3);
    if (verifyListLayout({30, 20, 10, 40, 50})) {
        std::cout << "--> STATUS: PASSED\n\n";
    } else {
        std::cout << "--> STATUS: FAILED\n" << "Got: "; printList();
    }

    std::cout << "Test 2b (Reversing the entire Linked List completely):\n";
    clearList();
    insert(10); insert(20); insert(30); insert(40); insert(50);
    reverse(1, 5);
    if (verifyListLayout({50, 40, 30, 20, 10})) {
        std::cout << "--> STATUS: PASSED\n\n";
    } else {
        std::cout << "--> STATUS: FAILED\n" << "Got: "; printList();
    }


    // -------------------------------------------------------------------------
    // TEST CASE 3: Reversing up to the Tail Node
    // -------------------------------------------------------------------------
    std::cout << "Test 3a (Subsegment terminating precisely at Tail [r = N]):\n";
    clearList();
    insert(10); insert(20); insert(30); insert(40); insert(50);
    reverse(3, 5);
    if (verifyListLayout({10, 20, 50, 40, 30})) {
        std::cout << "--> STATUS: PASSED\n\n";
    } else {
        std::cout << "--> STATUS: FAILED\n" << "Got: "; printList();
    }


    // -------------------------------------------------------------------------
    // TEST CASE 4: Standard Subsegment (In the Middle)
    // -------------------------------------------------------------------------
    std::cout << "Test 4a (Middle window isolated from Head and Tail):\n";
    clearList();
    insert(10); insert(20); insert(30); insert(40); insert(50);
    reverse(2, 4);
    if (verifyListLayout({10, 40, 30, 20, 50})) {
        std::cout << "--> STATUS: PASSED\n\n";
    } else {
        std::cout << "--> STATUS: FAILED\n" << "Got: "; printList();
    }

    std::cout << "Test 4b (Minimal middle window of length 2):\n";
    clearList();
    insert(10); insert(20); insert(30); insert(40);
    reverse(2, 3);
    if (verifyListLayout({10, 30, 20, 40})) {
        std::cout << "--> STATUS: PASSED\n\n";
    } else {
        std::cout << "--> STATUS: FAILED\n" << "Got: "; printList();
    }


    // -------------------------------------------------------------------------
    // TEST CASE 5: Out of Bounds Ranges
    // -------------------------------------------------------------------------
    std::cout << "Test 5a (Right index 'r' out of bounds [r > N]):\n";
    clearList();
    insert(10); insert(20); insert(30);
    reverse(2, 5); 
    // Depending on intent, this should either cleanly fail/return unchanged or reverse up to Max valid element.
    // Assuming design is to handle gracefully or return safely:
    if (verifyListLayout({10, 20, 30})) {
        std::cout << "--> STATUS: PASSED (Returned unmodified)\n\n";
    } else if (verifyListLayout({10, 30, 20})) {
        std::cout << "--> STATUS: PASSED (Reversed up to maximum available node)\n\n";
    } else {
        std::cout << "--> STATUS: FAILED\n" << "Got: "; printList();
    }

    clearList();
    return 0;
}