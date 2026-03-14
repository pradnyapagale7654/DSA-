#include<iostream>
using namespace std;
class node{
public:
int val;
node*left;
node*right;
node(int data){
    val=data;
    left=NULL;
    right=NULL;
}
};
static int idx=-1;
node*buildtree(int arr[]){
    idx++;
    if(arr[idx]==-1){
        return NULL;
    }
    node*newnode=new node(arr[idx]);
    newnode->left=buildtree(arr);
    newnode->right=buildtree(arr);
    return newnode;
}
int sumofleaves(node*root){
    if(root==NULL){
        return 0;
    }
    int sum=0;
    if(root->left!=NULL){
        if(root->left->left==NULL && root->left->right==NULL){
            sum=sum+root->left->val;
        }
        else{
            sum=sum+sumofleaves(root->left);
        }
    }
    sum=sum+sumofleaves(root->right);
    return sum;
}
void inorder(node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){
node*root=NULL;
int arr[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
root=buildtree(arr);
cout<<"inorder traversal of the tree is:"<<endl;
inorder(root);
cout<<"sum of left leaves:"<<sumofleaves(root);
return 0;
}