#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};
node* insert(node*root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
node*buildbst(vector<int>arr){
    node*root=NULL;
    for(int val:arr){
        root=insert(root,val);
    }
    return root;
}
node*prevnode=NULL;
int mindiff=INT_MAX;
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);      // left
    if(prevnode!=NULL){
        mindiff=min(mindiff,root->data-prevnode->data);
    }
    prevnode=root;
    inorder(root->right);     // right
}
int minimumdifference(node* root){
    prevnode=NULL;
     mindiff=INT_MAX;
    inorder(root);
    return mindiff;
}
int main(){
    vector<int>arr={3,6,1,8,9};
    node*bst=buildbst(arr);
    cout<<"Minimum Absolute Difference in BST: "<<minimumdifference(bst);
    return 0;
}