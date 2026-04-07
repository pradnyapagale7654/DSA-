#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class node{
public:
node*left;
node*right;
string key;
string val;

node(string k,string v){
    left=right=NULL;
    key=k;
    val=v;
}
};

node*insert(node*root,string key,string val){
    node*nn=new node (key,val);

    if(root==NULL){
        return nn;
    }

    if(key<root->key){
       root->left=insert(root->left,key,val);
    }
    else if(key>root->key){
        root->right=insert(root->right,key,val);
    }
    else{
        root->val=val;
    }

    return root;
}

void preorderrecursive(node*root){

    if(root == NULL)
        return;

    stack<node*>st;
    st.push(root);

    while(!st.empty()){
        node*temp=st.top();
        st.pop();

        cout<<temp->key<<":"<<temp->val<<" ";

        if(temp->right!=NULL){
            st.push(temp->right);
        }

        if(temp->left!=NULL){
            st.push(temp->left);
        }
    }
}

int main(){

node* root=NULL;

int n;
string key,val;

cout<<"Enter number of entries:";
cin>>n;

cout<<"Enter key value pairs:\n";

for(int i=0;i<n;i++){
    cin>>key>>val;
    root=insert(root,key,val);
}

cout<<"\nPreorder Traversal:\n";
preorderrecursive(root);

return 0;
}