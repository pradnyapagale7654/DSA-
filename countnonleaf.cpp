#include<iostream>
#include<vector>
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
static int idx=-1;
node*buildtree(vector<int>preorder){
 idx++;
 if(preorder[idx]==-1){
  return NULL;
 }
 node*root=new node(preorder[idx]);
 root->left=buildtree(preorder);
 root->right=buildtree(preorder);
 return root;
}
void inordertraversal(node*root){
    if(root==NULL){
        return ;
    }
    inordertraversal(root->left);
    cout<<root->data;
    inordertraversal(root->right);
}
int countnonleaf(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 0;
    }
    return 1+countnonleaf(root->left)+countnonleaf(root->right);
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,-1,-1};
    node*root=buildtree(preorder);
    inordertraversal(root);
    int sum=countnonleaf(root);
    cout<<"count of leaf is:"<<sum;
    return 0;
  }