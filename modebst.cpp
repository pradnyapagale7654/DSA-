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

int currnum=0;
int currfreq=0;
int maxfreq=0;
vector<int>result;
void dfs(node*root){
    if(root==NULL){
        return ;
    }
    dfs(root->left);
    
    if(root->data==currnum){
        currfreq++;
    }
    else{
        currnum=root->data;
        currfreq=1;
    }
    if(currfreq>maxfreq){
        result.clear();
        result.push_back(root->data);
        maxfreq=currfreq;
    }
    else if(currfreq==maxfreq){
        result.push_back(root->data);
    }
    dfs(root->right);
}
vector<int> findmode(node*root){
    dfs(root);
    return result;
}
int main(){
    vector<int>arr={3,6,1,3,1,5,8,9};
    node*bst=buildbst(arr);
    cout<<"Inorder Traversal of BST: ";
    inorder(bst);
    vector<int>modes=findmode(bst);
    cout<<"\nMode(s) in the BST: ";
    for(int mode : modes){
        cout << mode << " ";
    }

    return 0;
}
