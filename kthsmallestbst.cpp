
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

class Solution {
public:
void inorder(node* root,vector<int>&v){
    if(root==NULL){
        return ;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
    int kthSmallest(node* root, int k) {
        vector<int>v;
        inorder(root,v);
        
        return v[k-1];
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

   Solution s; 
   int k = 3;
    cout << "Kth smallest element = " << s.kthSmallest(root, k);

    return 0;
}

