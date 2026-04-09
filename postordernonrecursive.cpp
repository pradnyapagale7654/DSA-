#include<iostream>
#include<vector>
#include<stack>
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

void postordernon(node*root){
stack<node*>s1,s2;
s1.push(root);
while(!s1.empty()){
    node*curr=s1.top();
    s1.pop();
    s2.push(curr);
    if(curr->left!=NULL){
        s1.push(curr->left);
    }
    if(curr->right!=NULL){
        s1.push(curr->right);
    }
}
while(!s2.empty()){
    cout<<s2.top()->data<<" ";
    s2.pop();
}
}
int main(){
    vector<int>arr={3,6,1,8,9};
    node*bst=buildbst(arr);
    cout<<"postorder Traversal of BST: ";
    postordernon(bst);
    return 0;
}