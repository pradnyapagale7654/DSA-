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
bool search(node*root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(key<root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}
int main(){
    vector<int>arr={3,6,1,8,9};
    node*bst=buildbst(arr);
    cout<<"Inorder Traversal of BST: ";
    inorder(bst);
    cout<<"\nSearch 4: ";
    if(search(bst,4))
        cout<<"Found";
    else
        cout<<"Not Found";

    return 0;
}