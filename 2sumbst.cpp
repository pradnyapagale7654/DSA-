
#include <iostream>
#include <vector>
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

    void inorder(node* root, vector<int>& v) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, v);

        v.push_back(root->data);

        inorder(root->right, v);
    }

    bool twosumbst(node* root, int k) {
        vector<int> v;

        inorder(root, v);

        int st = 0;
        int end = v.size() - 1;

        while (st < end) {

            if (v[st] + v[end] == k) {
                return true;
            }
            else if (v[st] + v[end] > k) {
                end--;
            }
            else {
                st++;
            }
        }

        return false;
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

    int k = 9;

    if (s.twosumbst(root, k)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}

