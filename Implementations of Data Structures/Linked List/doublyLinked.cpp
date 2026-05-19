#include <iostream>
#include <string>

struct Node 
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;
// 1. Insert at End
void insert(int x) 
{
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

// 2. Insert At Specific Index
void insertAt(int x, int index) 
{
    Node *newNode = new Node;
    Node *temp = head;
    newNode->data = x;

    if (temp == nullptr) 
    {
        delete newNode;
        return;
    }

    for (int i = 1; i < index; i++) 
    {
        if (temp == nullptr) 
        {
            delete newNode;
            return;
        }
        temp = temp->next;
        if (index != 0 && temp == nullptr)
        {
            delete newNode;
            return;
        }
    }

    if (index == 0)
    {
        newNode->next = temp;
        if (temp != nullptr)
            temp->prev = newNode;
        else
            tail = newNode;
        head = newNode;
        newNode->prev = nullptr;
    }
    else
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

// 3. Delete At Specific Index
void deleteAt(int index)
{
    if (head == nullptr) return;

    Node *delNode = head;
    for (int i = 0; i < index && delNode != nullptr; i++) 
    {
        delNode = delNode->next;
    }
    
    if (delNode == nullptr) return;

    if (delNode->next == nullptr && delNode->prev == nullptr)
    {
        head = nullptr;
        tail = nullptr;
        delete (delNode);
        delNode = nullptr;
        return;
    }
    
    if (delNode->next != nullptr)
        delNode->next->prev = delNode->prev;
    else
    {
        delNode->prev->next = nullptr;
        tail = delNode->prev;
    }
    
    if (delNode->prev != nullptr)
        delNode->prev->next = delNode->next;
    else
    {
        delNode->next->prev = nullptr;
        head = delNode->next;
    }
    
    delete delNode;
    delNode = nullptr;
}


// Automated validation engine checking forward, backward link parity, and edge pointer tracking
// Helper to reset list state between test cases
void resetList() 
{
    Node *current = head;
    while (current != nullptr) 
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

bool verifyListState(const std::string& expectedPattern, int expectedHeadVal, int expectedTailVal) 
{
    if (head == nullptr && expectedPattern.empty()) return true;
    
    // Forward Pass Verification
    std::string forwardPattern = "";
    Node *forwardTemp = head;
    while (forwardTemp != nullptr) 
    {
        forwardPattern += std::to_string(forwardTemp->data) + " ";
        forwardTemp = forwardTemp->next;
    }
    
    // Reverse Pass Verification
    std::string reversePattern = "";
    Node *reverseTemp = tail;
    while (reverseTemp != nullptr) 
    {
        reversePattern = std::to_string(reverseTemp->data) + " " + reversePattern;
        reverseTemp = reverseTemp->prev;
    }

    bool patternsMatch = (forwardPattern == expectedPattern) && (reversePattern == expectedPattern);
    bool headMatches = (head != nullptr && head->data == expectedHeadVal) || (head == nullptr && expectedHeadVal == -1);
    bool tailMatches = (tail != nullptr && tail->data == expectedTailVal) || (tail == nullptr && expectedTailVal == -1);

    return patternsMatch && headMatches && tailMatches;
}

int main()
{
    std::cout << "==============================================================\n";
    std::cout << "     DOUBLY LINKED LIST CORE ENGINE AUTOMATED TEST HARNESS    \n";
    std::cout << "==============================================================\n\n";

    // ------------------------------------------------------------------------
    // TEST CASE 1: Standard End Insertions & Dynamic Head/Tail Integrity
    // ------------------------------------------------------------------------
    resetList();
    insert(10);
    insert(20);
    insert(30);
    if (verifyListState("10 20 30 ", 10, 30)) {
        std::cout << "[PASSED] Test 1: Standard End Insertions & Bidirectional Layout\n";
    } else {
        std::cout << "[FAILED] Test 1: Standard End Insertions & Bidirectional Layout\n";
    }
    std::cout << "\n";

    // ------------------------------------------------------------------------
    // TEST CASE 2: Index-Based Insertion Hazards (Front Boundaries)
    // ------------------------------------------------------------------------
    resetList();
    insert(10);
    insert(20);
    insertAt(5, 0); // Insert at index 0 (New Head)
    if (verifyListState("5 10 20 ", 5, 20)) {
        std::cout << "[PASSED] Test 2: Front Boundary Index Insertion (Head Swap)\n";
    } else {
        std::cout << "[FAILED] Test 2: Front Boundary Index Insertion (Head Swap)\n";
    }
    std::cout << "\n";

    // ------------------------------------------------------------------------
    // TEST CASE 3: Index-Based Insertion Hazards (Middle and Tail Boundaries)
    // ------------------------------------------------------------------------
    resetList();
    insert(10);
    insert(30);
    insertAt(20, 1); // Insert in the middle
    bool subStep1 = verifyListState("10 20 30 ", 10, 30);
    
    insertAt(40, 3); // Insert at the exact tail location
    bool subStep2 = verifyListState("10 20 30 40 ", 10, 40);

    if (subStep1 && subStep2) {
        std::cout << "[PASSED] Test 3: Intermediate and Rear Index Insertion Hazards\n";
    } else {
        std::cout << "[FAILED] Test 3: Intermediate and Rear Index Insertion Hazards\n";
    }
    std::cout << "\n";

    // ------------------------------------------------------------------------
    // TEST CASE 4: Deletion Structural Hazard Boundaries
    // ------------------------------------------------------------------------
    resetList();
    insert(10);
    insert(20);
    insert(30);
    insert(40); // 10 20 30 40

    deleteAt(1); // Delete Middle Node (20) -> 10 30 40
    bool delSub1 = verifyListState("10 30 40 ", 10, 40);

    deleteAt(0); // Delete Head Node (10) -> 30 40
    bool delSub2 = verifyListState("30 40 ", 30, 40);

    deleteAt(1); // Delete Tail Node (40) -> 30
    bool delSub3 = verifyListState("30 ", 30, 30);

    if (delSub1 && delSub2 && delSub3) {
        std::cout << "[PASSED] Test 4: Node Deletion Boundaries (Head, Middle, Tail Track)\n";
    } else {
        std::cout << "[FAILED] Test 4: Node Deletion Boundaries (Head, Middle, Tail Track)\n";
    }
    std::cout << "\n";

    // ------------------------------------------------------------------------
    // TEST CASE 5: Single Element Depletion To System Reset Empty State
    // ------------------------------------------------------------------------
    deleteAt(0); // Delete remaining node (30) -> Empty
    if (verifyListState("", -1, -1)) {
        std::cout << "[PASSED] Test 5: Full Element Depletion & System Pointer Reset\n";
    } else {
        std::cout << "[FAILED] Test 5: Full Element Depletion & System Pointer Reset\n";
    }
    std::cout << "\n";

    std::cout << "==============================================================\n";
    return 0;
}