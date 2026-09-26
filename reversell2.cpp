#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
    }
};

class Solution
{
public:
    ListNode *reversenode(ListNode *head, int left, int right)
    {

        if (head == NULL)
        {
            return NULL;
        }

        ListNode *curr = head;
        ListNode *prev = NULL;

        // Find the left position
        for (int i = 1; i < left; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        // prev = node before left
        // curr = node at left

        ListNode *before = prev;
        ListNode *start = curr;

        // Reverse left to right
        for (int i = left; i <= right; i++)
        {

            ListNode *next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // Connect the left part
        if (before != NULL)
        {
            before->next = prev;
        }
        else
        {
            head = prev;
        }

        // Connect the right part
        start->next = curr;

        return head;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        return reversenode(head, left, right);
    }
};

int main()
{

    // Create linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2;
    int right = 4;

    Solution obj;

    // Reverse from left to right
    head = obj.reverseBetween(head, left, right);

    // Print linked list
    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";

        temp = temp->next;
    }

    return 0;
}