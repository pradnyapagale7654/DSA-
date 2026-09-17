#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class solution {
public:
    node* lca(node* root, node* p, node* q) {
        if (root == NULL) return NULL;

        if (p->data > root->data && q->data > root->data) {
            // both in right subtree
            return lca(root->right, p, q);
        } else if (p->data < root->data && q->data < root->data) {
            // both in left subtree
            return lca(root->left, p, q);
        } else {
            // split point → root is LCA
            return root;
        }
    }
};

int main() {
    // Creating the BST
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->right = new node(7);

    solution s;

    // Example: find LCA of nodes 2 and 4
    node* p = root->left->left;   // node with value 2
    node* q = root->left->right;  // node with value 4

    node* res = s.lca(root, p, q);

    if (res != NULL) {
        cout << "LCA of " << p->data << " and " << q->data << " is: " << res->data << endl;
    } else {
        cout << "No LCA found." << endl;
    }

    return 0;
}
