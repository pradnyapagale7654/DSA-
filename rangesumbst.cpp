
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
int rangesum(node*root,int low,int high){
    if(root==NULL){
        return 0;
    }
    if(root->data>high){
        return rangesum(root->left,low,high);
    }
    if(root->data<low){
        return rangesum(root->right,low,high);
    }
    return root->data+rangesum(root->left,low,high)+rangesum(root->right,low,high);
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
   int ans=s.rangesum(root,3,5);
   cout<<"range sum between low and high:"<<ans;

    return 0;
}

