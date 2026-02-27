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
void solve(node*root,string path,vector<string>&ans){
    if(root==NULL){
        return;
    }
    path+=to_string(root->data);
    if(root->left==NULL && root->right==NULL){
        ans.push_back(path);
    }
    path+="->";
    solve(root->left,path,ans);
    solve(root->right,path,ans);
}
vector<string>binarytreepath(node*root){
    vector<string>ans;
    string path="";
    solve(root,path,ans);
    return ans;
}
int main(){
  vector<int>preorder={1,2,-1,-1,3,-1,-1};
  node*root=buildtree(preorder);
  inordertraversal(root);
  vector<string>result =binarytreepath(root);
  cout<<"\n path:";
  for(string s:result){
    cout<<"\n:"<<s;
  }
  return 0;
}