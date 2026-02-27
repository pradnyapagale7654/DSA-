#include<iostream>
#include<vector>
#include<queue>
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
  vector<vector<int>>levelorder(node*root){
      vector<vector<int>>ans;
      queue<node*>q;
      if(root==NULL){
          return ans;
      }
      q.push(root);
      while(!q.empty()){
          vector<int>level;
          int n=q.size();
          for(int i=0;i<n;i++){
              node*curr=q.front();
              q.pop();
              level.push_back(curr->data);
              if(curr->left!=NULL){
                 q.push(curr->left);
              }
              if(curr->right!=NULL){
                  q.push(curr->right);
              }
              
          }
          ans.push_back(level);
      }
      return ans;
  } 
int main(){
    vector<int>preorder={1,2,-1,-1,3,-1,-1};
    node*root=buildtree(preorder);
      vector<vector<int>>result=levelorder(root);
     cout << "Level order traversal:\n";
     for (auto level : result) {
         for (auto val : level) { 
             cout << val << " ";
             }
             cout << endl; }
    return 0;
  }