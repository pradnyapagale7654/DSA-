#include <iostream>
using namespace std;

// Node structure
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
    void reorder(Node *first)
    {
        // Base condition
        if (first == NULL || first->next == NULL)
        {
            return;
        }

        // Find the second-last node
        Node *last = first;

        while (last->next->next != NULL)
        {
            last = last->next;
        }

        // Last node
        Node *lastNode = last->next;

        // Remove last node
        last->next = NULL;

        // Store second node
        Node *next = first->next;

        // Put last node after first node
        first->next = lastNode;
        lastNode->next = next;

        // Recursively reorder remaining list
        reorder(next);
    }

    void reorderList(Node *head)
    {
        reorder(head);
    }
};

// Print linked list
void printList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    // Creating linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    // Create object
    solution obj;

    // Reorder list
    obj.reorderList(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}