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

void inorderrecursive(node*root){
    stack<node*>st;
    node*curr=root;

    while(curr!=NULL || !st.empty()){

        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }

        node*temp=st.top();
        st.pop();

        cout<<temp->key<<" : "<<temp->val<<endl;

        curr=temp->right;
    }
}

int main(){

node* root = NULL;

int n;
string key,value;

cout<<"Enter number of entries: ";
cin>>n;

cout<<"Enter key value pairs:\n";

for(int i=0;i<n;i++){
    cin>>key>>value;
    root = insert(root,key,value);
}

cout<<"\nDictionary (Sorted Order):\n";
inorderrecursive(root);

return 0;
}