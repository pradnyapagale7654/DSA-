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
bool getpath(node*root,int n,vector<int>&path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
      return true;
    }
    if(getpath(root->left,n,path) || getpath(root->right,n,path)){
        return true;
    }
    path.pop_back();
    return false;
}
int lca(node*root,int n1,int n2){
    vector<int>path1;
    vector<int>path2;
    getpath(root,n1,path1);
    getpath(root,n2,path2);
    int i;
    for(i=0;i<path1.size() && i<path2.size();i++){
        if(path1[i]!=path2[i]){
            break;
        }
    }
     return path1[i-1];
}
int main(){
  vector<int>preorder={1,2,-1,-1,3,-1,-1};
  node*root=buildtree(preorder);
  int n1,n2;
  cout<<"enter n1:";
  cin>>n1;
  cout<<"\n enter n2:";
  cin>>n2;
  cout<<"\nlowest common ancestor:"<<lca(root,n1,n2);
  return 0;
}