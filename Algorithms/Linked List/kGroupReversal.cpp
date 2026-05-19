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
void printList()// helper function to print the linked list
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << "\n\n";
}

void kGroupReversal(Node *&head, int k)// MAIN ALGORITHM FUNCTION
{

    if ( k <=1 || head==nullptr || head->next==nullptr)// if k is less than or equal to 1, or the list is empty or has only one node, no reversal is needed
        return;
    Node *prev = nullptr, *cur = head, *next = head->next;
    Node *checkNodes = head;
    Node *leftNode = nullptr, *tempTail = nullptr, *tempHead = nullptr;
    while (cur != nullptr)// traversing the list
    {
        for (int i = 1; i <= k; i++) // checking if k nodes are available
        {
            if (checkNodes == nullptr)// if not enough nodes are available, return
                return;
            tempTail = checkNodes;// storing the tail of the current group
            checkNodes = checkNodes->next;
        }
        if (tempHead != nullptr)// if this is not the first group, connect the previous group's tail to the current group's head
            leftNode = tempHead;
        tempHead = cur;// storing the head of the current group
        while (cur != checkNodes)// reversing the current group
        {
            if (tempHead == head)
                leftNode = nullptr;
            cur->next = prev;
            prev = cur;
            cur = next;
            if (cur != nullptr)
                next = cur->next;
        }
        if (tempHead == head)// if this is the first group, update the head pointer
            head = tempTail;
        
        if(leftNode!=nullptr)// connect the previous group's tail to the current group's head
        leftNode->next=tempTail;
        
        tempHead->next=cur;// connect the current group's tail to the next group's head
    }
}





//AI GENERATED TEST HARNESS

void clearList() // helper function to clear the linked list and free memory
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
void runTestCase(const std::string& testName, int k, const std::vector<int>& expected) {
    std::cout << "[TEST] " << testName << "\n";
    
    kGroupReversal(head, k);
    
    bool passed = true;
    Node* tmp = head;
    
    for (size_t i = 0; i < expected.size(); i++) {
        if (tmp == nullptr || tmp->data != expected[i]) {
            passed = false;
            break;
        }
        tmp = tmp->next;
    }
    if (tmp != nullptr) passed = false;
    
    if (passed) {
        std::cout << "  STATUS: PASSED\n\n";
    } else {
        std::cout << "  STATUS: FAILED\n";
        std::cout << "  Expected: ";
        for (int val : expected) std::cout << val << " ";
        std::cout << "\n  Got:      ";
        printList();
        std::cout << "\n";
    }
}

void populateList(const std::vector<int>& values) {
    clearList();
    for (int val : values) insert(val);
}

int main() {
    std::cout << "=====================================================\n";
    std::cout << "   ALGORITHM TEST SUITE: K-GROUP REVERSAL                      \n";
    std::cout << "=====================================================\n\n";

    // TESTCASE 1: Standard Optimal Path
    populateList({1, 2, 3, 4, 5, 6});
    runTestCase("Standard Multiples (k=2)", 2, {2, 1, 4, 3, 6, 5});

    // TESTCASE 2: Leftover nodes 
    populateList({1, 2, 3, 4, 5});
    runTestCase("Boundary Conditions (k=3, 2 leftovers)", 3, {3, 2, 1, 4, 5});

    // TESTCASE 3: k equals exact list size
    populateList({1, 2, 3, 4});
    runTestCase("Exact List Size (k=4)", 4, {4, 3, 2, 1});

    // TESTCASE 4: k is larger than list size
    populateList({1, 2, 3});
    runTestCase("k Larger Than List (k=5)", 5, {1, 2, 3});

    // TESTCASE 5: Empty List Handling
    clearList();
    runTestCase("Empty List Layout", 2, {});

    // TESTCASE 6: Single Element List
    populateList({99});
    runTestCase("Single Element Layout (k=2)", 2, {99});

    // TESTCASE 7: Invalid/Null Parameters
    populateList({10, 20, 30});
    runTestCase("Parameter Safety (k=0)", 0, {10, 20, 30});

    populateList({10, 20, 30});
    runTestCase("Parameter Safety (k=-1)", -1, {10, 20, 30});

    std::cout << "=====================================================\n";
    std::cout << "   TEST SUITE EXECUTION COMPLETE                               \n";
    std::cout << "=====================================================\n";

    clearList();
    return 0;
}