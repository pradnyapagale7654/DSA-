#include<iostream>
#include<vector>
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
bool haspathsum(node*root,int targetsum){
    if(root==NULL){
        return false;
    }
    if(root->left==NULL && root->right==NULL){
        return targetsum==root->data;
    }
    int remaining=targetsum-root->data;
    return haspathsum(root->left,remaining)||
    haspathsum(root->right,remaining);
}
int main(){
  vector<int>preorder={1,2,-1,-1,3,-1,-1};
  node*root=buildtree(preorder);
  inordertraversal(root);
  cout<<"1 or 0:"<<haspathsum(root,3);
  return 0;
}