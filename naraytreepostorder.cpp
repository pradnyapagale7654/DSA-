#include<iostream>
#include<vector>
using namespace std;
class node {
    public:
vector<node*>children;
int data;
node(int val){
    data=val;
}
};

class solution {
public:
    void dfs(node* root, vector<int>& ans) {
        if (root == NULL) return;

        // Step 1: Visit children
        for (node* child : root->children) {
            dfs(child, ans);
        }

        // Step 2: Visit root
        ans.push_back(root->data);
    }

    vector<int> postorderTraversal(node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};
int main() {
    node* root = new node(1);
    node* child1 = new node(2);
    node* child2 = new node(3);
    node* child3 = new node(4);
    node* child4 = new node(5);
    node* child5 = new node(6);

    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);

    child1->children.push_back(child4);
    child3->children.push_back(child5);

    solution sol;
    vector<int> postorder = sol.postorderTraversal(root);

    for (int val : postorder) {
        cout << val << " ";
    }

    return 0;
}