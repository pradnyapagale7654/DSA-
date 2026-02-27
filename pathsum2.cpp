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
void solve(node*root,int targetsum,vector<int>path,vector<vector<int>>&ans){
    if(root==NULL){
        return ;
    }
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        if(root->data==targetsum){
            ans.push_back(path);
        }
    }
    solve(root->left,targetsum-root->data,path,ans);
    solve(root->right,targetsum-root->data,path,ans);
    path.pop_back();
}
vector<vector<int>>pathsum(node*root,int targetsum){
vector<vector<int>>ans;
vector<int>path;
solve(root,targetsum,path,ans);
return ans;
}
int main(){
  vector<int>preorder={1,2,-1,-1,3,-1,-1};
  node*root=buildtree(preorder);
  inordertraversal(root);
  vector<vector<int>>result=pathsum(root,3);
  cout<<"pathsum is:";
  for(int n:result){
    cout<<n;
  }

  return 0;
}