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
int mindepth(node*root){
    if(root==NULL){
        return 0;
    }
    int leftsubtree=mindepth(root->left);
    int rightsubtree=mindepth(root->right);
    if(leftsubtree==0){
        return rightsubtree+1;
    }
    if(rightsubtree==0){
        return leftsubtree+1;
    }
    return min(leftsubtree,rightsubtree)+1;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,-1,-1};
    node*root=buildtree(preorder);
    inorder(root);
    int result=mindepth(root);
    cout<<"mindepth is:"<<result;
    return 0;
}