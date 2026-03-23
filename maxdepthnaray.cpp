#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N-ary Tree Node
class Node {
public:
    int data;
    vector<Node*> children;

    Node(int val) {
        data = val;
    }
};

int maxDepth(Node* root) {
    if (root == NULL)
        return 0;

    int ans = 0;

    // Traverse all children
    for (Node* child : root->children) {
        ans = max(ans, maxDepth(child));
    }

    return ans + 1;
}

int main() {
    Node* root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);
    Node* child4 = new Node(5);
    Node* child5 = new Node(6);

    // Building N-ary tree
    // add childrens to root
    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);
   //add child to node 1
    child1->children.push_back(child4);
    //add child to node3 
    child3->children.push_back(child5);

    /*
            1
         /  |  \
        2   3   4
       /         \
      5           6
    */

    cout << "Max Depth of N-ary Tree: " << maxDepth(root);

    return 0;
}