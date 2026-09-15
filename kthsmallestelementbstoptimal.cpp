
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
void inorder(node* root,int &count,int k,int &ans){
    if(root==NULL){
        return ;
    }
    inorder(root->left,count,k,ans);
    count++;
    if(count==k){
        ans=root->data;
        return;
    }
    inorder(root->right,count,k,ans);
}
    int kthSmallest(node* root, int k) {
        int count=0;
        int ans=-1;
        inorder(root,count,k,ans);
        
        return ans;
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

