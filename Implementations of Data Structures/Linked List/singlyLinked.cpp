#include <iostream>
#include <string>

struct Node
{
    int data;
    Node *next;
};

// Global pointers managed across operations
Node *head = nullptr;
Node *tail = nullptr;

// 1. Insert at Beginning
void InsertAtBeg(int x)
{
    Node *tmp = new Node;
    tmp->data = x;
    tmp->next = head;
    head = tmp;
    if (tail == nullptr)
    {
        tail = tmp;
    }
}

// 2. Insert at End - O(1) Time
inline void linkPrevNode(Node *tmp)
{
    tail->next = tmp;
    tail = tmp;
}

void insertAtEnd(int x)
{
    Node *tmp = new Node;
    tmp->next = nullptr;
    tmp->data = x;
    if (head == nullptr)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        linkPrevNode(tmp);
    }
}

// 3. Insert at Nth Position
void insertAtNth(int x, int index)
{
    Node *newnode = new Node;
    newnode->data = x;
    newnode->next = nullptr;

    if (index == 0 || head == nullptr)
    {
        newnode->next = head;
        head = newnode;
        if (tail == nullptr)
        {
            tail = newnode;
        }
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < index && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        if (newnode->next == nullptr)
        {
            tail = newnode;
        }
    }
}

// 4. Delete at Nth Position
void deleteAt(int index)
{
    if (head == nullptr)
        return;

    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        delete temp;
        return;
    }

    Node *temp1 = head;
    for (int i = 1; i < index && temp1->next != nullptr; i++)
    {
        temp1 = temp1->next;
    }

    if (temp1->next == nullptr)
        return; // Out of bounds safety

    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    if (temp1->next == nullptr)
    {
        tail = temp1;
    }
    delete temp2;
}

// Helper to verify list structure state for automated testing
bool verifyListState(const std::string &expectedPattern, int expectedTailVal)
{
    if (head == nullptr && expectedPattern.empty())
        return true;

    std::string actualPattern = "";
    Node *temp = head;
    while (temp != nullptr)
    {
        actualPattern += std::to_string(temp->data) + " ";
        temp = temp->next;
    }

    bool matchPattern = (actualPattern == expectedPattern);
    bool matchTail = (tail != nullptr && tail->data == expectedTailVal) || (tail == nullptr && expectedTailVal == -1);

    return matchPattern && matchTail;
}
// Helper to check and reset state between tests
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

int main()
{
    std::cout << "==============================================================\n";
    std::cout << "      SINGLY LINKED LIST CORE METHOD AUTOMATED TEST HARNESS   \n";
    std::cout << "==============================================================\n\n";

    // ------------------------------------------------------------------------
    // TEST CASE 1: Standard Sequential Insertions at Beginning & Tail Verification
    // ------------------------------------------------------------------------
    resetList();
    InsertAtBeg(10);
    InsertAtBeg(20);
    InsertAtBeg(30);
    if (verifyListState("30 20 10 ", 10))
    {
        std::cout << "[PASSED] Test 1: Sequential Front Insertions & Tail Integrity\n";
    }
    else
    {
        std::cout << "[FAILED] Test 1: Sequential Front Insertions & Tail Integrity\n";
    }
    std::cout << "\n";

    // ------------------------------------------------------------------------
    // TEST CASE 2: Efficient End Insertions O(1)
    // ------------------------------------------------------------------------
    resetList();
    insertAtEnd(100);
    insertAtEnd(200);
    insertAtEnd(300);
    if (verifyListState("100 200 300 ", 300))
    {
        std::cout << "[PASSED] Test 2: O(1) Tail Insertions & Tracking\n";
    }
    else
    {
        std::cout << "[FAILED] Test 2: O(1) Tail Insertions & Tracking\n";
    }
    std::cout << "\n";

    // ------------------------------------------------------------------------
    // TEST CASE 3: Nth Position Random Insertions (Middle, Front Hazard)
    // ------------------------------------------------------------------------
    resetList();
    insertAtNth(10, 0); // List: 10 (Tail: 10)
    insertAtNth(30, 1); // List: 10 30 (Tail: 30)
    insertAtNth(20, 1); // List: 10 20 30 (Tail: 30)
    insertAtNth(5, 0);  // List: 5 10 20 30 (Tail: 30)
    if (verifyListState("5 10 20 30 ", 30))
    {
        std::cout << "[PASSED] Test 3: Structural Middle & Nth Index Insertions\n";
    }
    else
    {
        std::cout << "[FAILED] Test 3: Structural Middle & Nth Index Insertions\n";
    }
    std::cout << "\n";

    // ------------------------------------------------------------------------
    // TEST CASE 4: Deletion Boundaries (Front, Middle, Tail Hazards)
    // ------------------------------------------------------------------------
    resetList();
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40); // List: 10 20 30 40

    deleteAt(1); // Delete 20 -> List: 10 30 40
    bool subStep1 = verifyListState("10 30 40 ", 40);

    deleteAt(0); // Delete Head (10) -> List: 30 40
    bool subStep2 = verifyListState("30 40 ", 40);

    deleteAt(1); // Delete Tail (40) -> List: 30 (Tail should point to 30)
    bool subStep3 = verifyListState("30 ", 30);

    if (subStep1 && subStep2 && subStep3)
    {
        std::cout << "[PASSED] Test 4: Delete Boundaries (Head, Intermediate, Tail Updates)\n";
    }
    else
    {
        std::cout << "[FAILED] Test 4: Delete Boundaries (Head, Intermediate, Tail Updates)\n";
    }
    std::cout << "\n";

    // ------------------------------------------------------------------------
    // TEST CASE 5: Complete Node Depletion / Empty State Hazard
    // ------------------------------------------------------------------------
    deleteAt(0); // Delete remaining final node -> Empty List
    if (verifyListState("", -1))
    {
        std::cout << "[PASSED] Test 5: Full Element Depletion & System Reset Hazard\n";
    }
    else
    {
        std::cout << "[FAILED] Test 5: Full Element Depletion & System Reset Hazard\n";
    }
    std::cout << "\n";

    std::cout << "==============================================================\n";
    return 0;
}