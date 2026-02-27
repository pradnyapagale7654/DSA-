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
int issum(node*root){
    if(root==NULL){
        return 1;
    }
    if(root->left==NULL && root->right==NULL){
      return 1;
    }
    int left=0; // 0 because local variable can store some grbage value it it thats why
    int right=0;
    if(root->left!=NULL){
      left=root->left->data;
    }
    if(root->right!=  NULL){
      right=root->right->data;
    }
    if(root->data==left+right && issum(root->left) && issum(root->right)){
      return 1;
    }
    return 0;
}
int main(){
  vector<int>preorder={1,2,-1,-1,3,-1,-1};
  node*root=buildtree(preorder);
  inordertraversal(root);
  cout<<"issum:";
  int res=issum(root);
  cout<<res;
  return 0;
}