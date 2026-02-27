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
node*getis(node*root){
    while(root->left!=NULL && root!=NULL){
        root=root->left;
    }
    return root;
}
node*delnode(node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->data){
        root->left=delnode(root->left,key);
    }
    else if(key>root->data){
        root->right=delnode(root->right,key);
    }
    else{
        //root->data==key
        if(root->left==NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        else{
            // 2 childrens
            node*is=getis(root->right);
            root->data=is->data;
            root->right=delnode(root->right,is->data);
        }
    }
    return root;
}
int main(){
    vector<int>arr={3,6,1,8,9};
    node*bst=buildbst(arr);
    cout<<"Inorder Traversal of BST: ";
    inorder(bst);
    cout<<"bst after deletion:";
    delnode(bst,8);
    inorder(bst);
    return 0;
}