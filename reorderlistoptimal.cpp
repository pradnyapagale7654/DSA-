#include <iostream>
using namespace std;

// Node
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class solution
{
public:
    void reorderList(Node *head)
    {
        // If list has 0 or 1 node
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        // -----------------------------
        // STEP 1: Find middle
        // -----------------------------

        Node *slow = head;
        Node *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is at middle
        // 1 -> 2 -> 3 -> 4 -> 5
        //          slow

        // Second half starts after slow
        Node *second = slow->next;

        // Break the list
        slow->next = NULL;

        // -----------------------------
        // STEP 2: Reverse second half
        // -----------------------------

        Node *prev = NULL;
        Node *curr = second;

        while (curr != NULL)
        {
            Node *next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // prev is the head of reversed second half
        second = prev;

        // -----------------------------
        // STEP 3: Merge both halves
        // -----------------------------

        Node *first = head;

        while (second != NULL)
        {
            Node *firstNext = first->next;
            Node *secondNext = second->next;

            // Connect first node to second node
            first->next = second;

            // Connect second node to next first node
            second->next = firstNext;

            // Move forward
            first = firstNext;
            second = secondNext;
        }
    }
};

// Print linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    // 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    solution obj;

    obj.reorderList(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}