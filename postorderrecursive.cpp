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

void postorderrecursive(node*root){

    if(root==NULL){
        return;
    }

    stack<node*>s1;
    stack<node*>s2;

    s1.push(root);

    while(!s1.empty()){
        node*temp=s1.top();
        s1.pop();

        s2.push(temp);

        if(temp->left!=NULL){
            s1.push(temp->left);
        }

        if(temp->right!=NULL){
            s1.push(temp->right);
        }
    }

    while(!s2.empty()){
        cout<<s2.top()->key<<":"<<s2.top()->val<<" ";
        s2.pop();
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

cout<<"\nPostorder Traversal:\n";
postorderrecursive(root);

return 0;
}