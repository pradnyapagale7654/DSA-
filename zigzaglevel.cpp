#include<iostream>
#include<vector>
#include<queue>
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
vector<vector<int>>zigzag(node*root){
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    queue<node*>q;
    q.push(root);
    bool lefttoright=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>level(size);
        for(int i=0;i<size;i++){
            node*temp=q.front();
            q.pop();
            int index=lefttoright?i:size-1-i;
            level[index]=temp->data;
            if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
        }
        lefttoright = !lefttoright;
            ans.push_back(level);
    }
    return ans;
}
int main(){
  vector<int>preorder={1,2,-1,-1,3,-1,-1};
  node*root=buildtree(preorder);
  vector<vector<int>>result=zigzag(root);
  for(auto level : result){
    for(auto val : level){
        cout << val << " ";
    }
    cout << endl;
}
  return 0;
}