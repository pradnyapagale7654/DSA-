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
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
int height(node*root){
    if(root==NULL){
        return 0;
    }
    int left1=height(root->left);
    int right1=height(root->right);
    return max(left1,right1)+1;
}
int diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+height(root->right);
    int ans =max(op1,max(op2,op3));
    return ans;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,-1,-1};
    node*root=buildtree(preorder);
    inorder(root);
    int heightbt=height(root);
    cout<<"\n"<<heightbt;
    int d=diameter(root);
    cout<<"\n"<<d;
    return 0;
}