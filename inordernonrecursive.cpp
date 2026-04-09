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

void inordernon(node*root){
stack<node*>st;
node*curr=root;
while(curr!=NULL || !st.empty() ){
    while(curr!=NULL){
    st.push(curr);
    curr=curr->left;
    }
    curr=st.top();
    st.pop();
    cout<<curr->data<<" ";
    curr=curr->right;
}
}
int main(){
    vector<int>arr={3,6,1,8,9};
    node*bst=buildbst(arr);
    cout<<"Inorder Traversal of BST: ";
    inordernon(bst);
    return 0;
}