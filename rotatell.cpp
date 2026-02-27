#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node() {
        data = 0;
        next = NULL;
    }
    node(int val) {
        data = val;
        next = NULL;
    }
};

class ll {
public:
    node* head;
    ll() {
        head = NULL;
    }

    void insert_beg(int val) {
        node* nn = new node(val);
        nn->next = head;
        head = nn;
    }

    void print() {
        if (head == NULL) {
            cout << "list is empty\n";
            return;
        }
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    node* rotate(node* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // Find length and tail
        node* curr = head;
        int len = 1;
        while (curr->next != NULL) {
            curr = curr->next;
            len++;
        }
        node* tail = curr; // store tail

        // Make list circular
        tail->next = head;

        // Normalize k
        k %= len;
        if (k == 0) {
            tail->next = NULL; // break circle
            return head;
        }

        // Find new tail (len - k steps from start)
        curr = head;
        for (int i = 1; i < len - k; i++) {
            curr = curr->next;
        }

        // New head is after new tail
        head = curr->next;
        curr->next = NULL;

        return head;
    }
};

int main() {
    ll l;
    l.insert_beg(5);
    l.insert_beg(4);
    l.insert_beg(3);
    l.insert_beg(2);

    cout << "Original list:\n";
    l.print();

    // Rotate by 2 positions
    l.head = l.rotate(l.head, 2);

    cout << "After rotation:\n";
    l.print();

    return 0;
}
