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
bool isleaf(node*root){
    if(root==NULL){
        return false;
    }
    return root->left==NULL && root->right==NULL;
}
void leftboundry(node*root,vector<int>&res){
    if(root==NULL){
        return;
    }
    if(isleaf(root)){
        return ;
    }
    res.push_back(root->data);
   if(root->left!=NULL){
    leftboundry(root->left,res);
   }
   else
   leftboundry(root->right, res);
}
void leafboundry(node*root,vector<int>&res){
    if(root==NULL){
        return ;
    }
    if(isleaf(root)){
        res.push_back(root->data);
        return;
    }
    leafboundry(root->left,res);
    leafboundry(root->right,res);
}
void rightboundry(node*root,vector<int>&res){
    if(root==NULL){
        return ;
    }
    if(isleaf(root)){
        return ;
    }
    if(root->right!=NULL){
        rightboundry(root->right,res);
    }
    else{
        rightboundry(root->left,res);
    }
    res.push_back(root->data);
}
vector<int>boundry(node*root,vector<int>&res){
    if(root==NULL){
        return {};
    }
    if(!isleaf(root)){
        res.push_back(root->data);
    }
    leftboundry(root->left,res);
    leafboundry(root,res);
    rightboundry(root->right,res);
    return res;
}
int main(){
  vector<int>preorder={1,2,-1,-1,3,-1,-1};
  node*root=buildtree(preorder);
  inordertraversal(root);
  vector<int> res;
  vector<int>ans=boundry(root,res);
  cout<<"Boundary Traversal: ";
    for(int x:ans)
        cout<<x<<" ";

  return 0;
}