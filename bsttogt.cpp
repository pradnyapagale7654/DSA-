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
    int sum = 0;

    node* bsttogt(node* root) {
        if (root == NULL) return NULL;

        // reverse inorder traversal
        bsttogt(root->right);

        sum += root->data;
        root->data = sum;

        bsttogt(root->left);

        return root;
    }
};

// helper to print inorder traversal
void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Creating the BST
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->right = new node(7);

    solution s;
    s.bsttogt(root);

    cout << "Inorder traversal after converting BST to Greater Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
