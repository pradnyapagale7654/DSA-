#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class node{
    public:
vector<node*>children;
int data;
node(int val){
    data=val;
}
};
class solution {
public:
    vector<int> preorderTraversal(node* root) {
         vector<int>ans;
        if (root == NULL)
         return ans;;
       // Step 1: Visit root
        ans.push_back(root->data);

        // Step 2: Visit all children
        for (node* child : root->children) {
           vector<int>temp= preorderTraversal(child);
           ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};
int main(){
  node*root=new node(1);
  node*child1=new node(2);
  node*child2=new node(3);
  node*child3=new node(4);
  node*child4=new node(5);
    node*child5=new node(6);
    // Building N-ary tree
    // add childrens to root
    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);
    //add child to node 1
    child1->children.push_back(child4);
    //add child to node3
    child3->children.push_back(child5);
    solution sol;
    vector<int>preorder=sol.preorderTraversal(root);
    for(int val:preorder){
        cout<<val<<" ";
    }
    return 0;
}