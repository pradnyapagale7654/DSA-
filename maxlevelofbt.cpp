#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
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
int maxlevel(node*root){
    if(root==NULL){
        return 0;
    }
    int sum;
    int maxsum=INT_MIN;
    int level=0;
    int ans=0;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        level++;
        sum=0;
        int size=q.size(); // no of elements on each level
        while(size--){
            node*temp=q.front();
            q.pop();
            sum=sum+temp->data;
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        if(sum>maxsum){
            maxsum=sum;
            ans=level;
        }
    }
    return ans;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,-1,-1};
    node*root=buildtree(preorder);
    cout<<"maximum sum of level:"<<maxlevel(root);
    return 0;
}