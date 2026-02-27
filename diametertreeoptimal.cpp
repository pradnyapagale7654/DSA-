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
int height(node*root){
    if(root==NULL){
        return 0;
    }
    int left1=height(root->left);
    int right1=height(root->right);
   int ans=0;
    ans=max(ans,left1+right1);
    return max(left1,right1)+1;
}
int diameter(node*root){
   height(root);
    return ans;
}

