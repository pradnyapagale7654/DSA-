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
void levelorder(node*root){
    queue<node*>q;
    if(root==NULL){
        return;
    }
    q.push(root);
    q.push(NULL);  //next line 
    while(q.size()>0){
      node*curr=q.front();
      q.pop();
      if(curr==NULL){
        if(!q.empty()){
          cout<<endl;
          q.push(NULL);
          continue;
        }
        else{
          break;
        }
      }
      cout<<curr->data;
      if(curr->left!=NULL){
        q.push(curr->left);
      }
      if(curr->right!=NULL){
        q.push(curr->right);
      }
    }
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,-1,-1};
    node*root=buildtree(preorder);
    levelorder(root);
    return 0;
  }