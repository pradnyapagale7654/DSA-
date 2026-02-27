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
bool issame(node*p,node*q){
  if(p==NULL || q==NULL){
    return p==q;
  }
  return issame(p->left,q->left)&& issame(p->right,q->right) && p->data==q->data;
}
bool issubtree(node*p,node*q){
    if(p==NULL || q==NULL){
        return p==q;
    }
    if(p->data==q->data && issame(p,q)){
        return true;
    }
    return issubtree(p->left,q)||issubtree(p->right,q);
}
int main(){
  vector<int>preorder1={1,2,-1,-1,3,-1,-1};
  idx = -1; 
  node*root1=buildtree(preorder1);
  vector<int> preorder2 = {1,2,-1,-1,3,-1,-1};
  idx = -1; 
  node*root2=buildtree(preorder2);
  inordertraversal(root1);
  inordertraversal(root2);
  if(issubtree(root1, root2)){
  cout<<"YES";
  }
else{
  cout<<"NO";
}
  return 0;
}