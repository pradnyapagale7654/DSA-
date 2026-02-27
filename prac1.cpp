#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class node{
  public:
node*left;
node*right;
int data;
node(){
  left=right=NULL;
  data=0;
}
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
node* bst(vector<int>arr){
  node*root=NULL;
for(int s:arr){
  root=insert(root,s);
}
return root;
}
void inorder(node*root){
  if(root==NULL){
    return ;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
bool search(node*root,int key){
  if(root==NULL){
    return false;
  }
  if(key==root->data){
    return true;
  }
  if(key<root->data){
    return search(root->left,key);
  }
  else{
    return search(root->right,key);
  }
}
node*getis(node*root){
  while(root!=NULL && root->left!=NULL){
    root=root->left;
  }
  return root;
}
node*delnode(node*root,int val){
  if(root==NULL){
    return NULL;
  }
  if(val<root->data){
    root->left=delnode(root->left,val);
  }
  else if(val>root->data){
    root->right=delnode(root->right,val);
  }
  else{
    //root==val
    if(root->left==NULL && root->right==NULL){
      delete root;
      root=NULL;
      return NULL;
    }
    else if(root->left==NULL){
      node*temp=root->right;
      delete root;
      return temp;
    }
    else if(root->right==NULL){
      node*temp=root->left;
      delete root;
      return temp;
    }
    else{
      //two childs
      node*is=getis(root->right);
      root->data=is->data;
      root->right=delnode(root->right,val);

    }
  }
  return root;
}
int main(){
  vector<int>arr={1,6,3,4,5};
  node*root=bst(arr);
  inorder(root);
  cout<<"\n key is present or not:";
  cout<<search(root,5);
  delnode(root,4);
  cout<<"\n after deletion the tree is:";
  inorder(root);
  return 0;
}