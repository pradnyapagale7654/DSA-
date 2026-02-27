#include<iostream>
#include<vector>
using namespace std;

// Tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // recursive builder
    TreeNode* build(vector<int>& nums,int st,int end){
        if(st > end) return NULL;

        int mid = st + (end - st)/2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(nums, st, mid-1);
        root->right = build(nums, mid+1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
};

// preorder print
void preorder(TreeNode* root){
    if(root == NULL) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter sorted array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    Solution obj;
    TreeNode* root = obj.sortedArrayToBST(nums);

    cout<<"Preorder of BST: ";
    preorder(root);

    return 0;
}
