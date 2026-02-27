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

int height(node*root){
    if(root==NULL)
    return 0;
    int left1=height(root->left);
    if(left1==-1){
        return -1;
    }
    int right1=height(root->right);
    if(right1==-1){
        return -1;
    }
    if(abs(left1-right1)>1){
        return -1;
    }
    return max(left1,right1)+1;
}
bool isbalanced(node*root){
    return height(root)!=-1;
}
int main(){
  vector<int>preorder={1,2,-1,-1,3,-1,-1};
  node*root=buildtree(preorder);
  inordertraversal(root);
  bool ans = isbalanced(root);
  cout<<ans;
  return 0;
}