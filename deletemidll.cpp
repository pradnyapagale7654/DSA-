#include <iostream>
#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: single node
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Move fast by 2 steps, slow by 1 step
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // Delete the middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};

// Utility function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from array
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Example: [1,3,4,7,1,2,6]
    vector<int> vals = {1,3,4,7,1,2,6};
    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    head = sol.deleteMiddle(head);

    cout << "After Deleting Middle: ";
    printList(head);

    return 0;
}
