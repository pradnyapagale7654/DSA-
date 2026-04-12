#include<iostream>
#include<vector>
#include<algorithm>
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
void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);      // left
    cout << root->data << " "; // root
    inorder(root->right);     // right
}
bool isvalid(node*root,node*max,node*min){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
      return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    return isvalid(root->left,root,min) && isvalid(root->right,max,root);
}
bool isvalidbst(node*root){
    return isvalid(root,NULL,NULL);
}
int main(){
    vector<int>arr={3,6,1,8,9};
    node*bst=buildbst(arr);
    cout<<"Inorder Traversal of BST: ";
    inorder(bst);
    cout<<"\n is bst valid (yes=1 or no =0):"<<isvalidbst(bst);
    return 0;
}