#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class node{
public:
    node*left;
    node*right;
    int data;

    node(int val){
        data=val;
        left=right=NULL;
    }
};

// Build tree from level order (Complete Binary Tree)
node* buildtree(vector<int> arr){
    if(arr.size()==0) return NULL;

    node* root = new node(arr[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;

    while(i < arr.size()){
        node* curr = q.front();
        q.pop();

        // left child
        curr->left = new node(arr[i++]);
        q.push(curr->left);

        // right child
        if(i < arr.size()){
            curr->right = new node(arr[i++]);
            q.push(curr->right);
        }
    }

    return root;
}

void inordertraversal(node*root){
    if(root==NULL){
        return ;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}

bool getpath(node*root,int n,vector<int>&path){
    if(root==NULL){
        return false;
    }

    path.push_back(root->data);

    if(root->data==n){
        return true;
    }

    if(getpath(root->left,n,path) || getpath(root->right,n,path)){
        return true;
    }

    path.pop_back();
    return false;
}

int lca(node*root,int n1,int n2){
    vector<int>path1;
    vector<int>path2;

    getpath(root,n1,path1);
    getpath(root,n2,path2);

    int i;
    for(i=0;i<path1.size() && i<path2.size();i++){
        if(path1[i]!=path2[i]){
            break;
        }
    }

    return path1[i-1];
}

int main(){

    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    node* root = buildtree(arr);

    int n1,n2;

    cout<<"Enter element 1: ";
    cin>>n1;

    cout<<"Enter element 2: ";
    cin>>n2;

    cout<<"Lowest Common Ancestor: "<<lca(root,n1,n2);

    return 0;
}