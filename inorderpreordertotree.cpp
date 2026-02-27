#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    int findelement(vector<int>&inorder,int element,int n){
  for(int i=0;i<n;i++){
    if(inorder[i]==element){
        return i;
    }
  }
  return -1;
    }
    node*solve(vector<int>&inorder,vector<int>&preorder,int &index,int inst,int inend,int n){
        if(inst<=inend){
            return NULL;
        }
        int temp=preorder[index++];
        node*root=new node(temp);
        int pos=findelement(inorder,temp,n);
        root->left=solve(inorder,preorder,index,inst,pos-1,n);
        root->right=solve(inorder,preorder,index,pos+1,inend,n);
    }
    vector<int>buildtree(vector<int>&inorder,vector<int>&preorder){
        int preorderidx=0;
        vector<int>ans=solve(inorder,preorder,preorderidx,0,n-1,n);
        return ans;
    }
};