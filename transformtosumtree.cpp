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
int sumtree(node*root){
    if(root==NULL){
        return 0;
    }
    int leftsum=sumtree(root->left);
    int rightsum=sumtree(root->right);
    root->data+=leftsum+rightsum;
    return root->data;
}
int main(){
  vector<int>preorder={1,2,-1,-1,3,-1,-1};
  node*root=buildtree(preorder);
  inordertraversal(root);
  cout<<"sumtree:";
  sumtree(root);
  inordertraversal(root);
  return 0;
}