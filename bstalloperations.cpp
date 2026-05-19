#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
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
node*insert(node*root,int val){
    if(root==NULL){
        return new node(val);
    }
    else if(val<root->data){
        root->left=insert(root->left,val);
    }
    else {
        root->right=insert(root->right,val);
    }
    return root;
}
void inorder(node*root){
    if(root==NULL){
       return ;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void inorderrecu(node*root){
    stack<node*>st;
    if(root==NULL){
        return;
    }
    node*temp=root;
    while(temp!=NULL || !st.empty()){
        while(temp!=NULL){
        st.push(temp);
        temp=temp->left;
    }
     temp=st.top();
    st.pop();
    cout<<temp->data<<" ";
    temp=temp->right;
    }
}
void preorderrec(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderrec(root->left);
    preorderrec(root->right);
}
void preordernonrec(node*root){
    if(root==NULL){
        return;
    }
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        node*temp=st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right!=NULL){
            st.push(temp->right);
        }
        if(temp->left!=NULL){
            st.push(temp->left);
        }
    }
}
void postorderrec(node*root){
    if(root==NULL){
        return;
    }
    postorderrec(root->left);
    postorderrec(root->right);
    cout<<root->data<<" ";
}
void postordernonrec(node*root){
    if(root==NULL){
        return;
    }
    stack<node*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        node*t=s1.top();
        s1.pop();
        s2.push(t);
        if(t->left!=NULL){
            s1.push(t->left);
        }
        if(t->right!=NULL){
            s1.push(t->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}
void levelorder(node*root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}
void search(node*root,int key){
    if(root==NULL){
        cout<<"empty tree";
        return ;
    }
    if(key<root->data){
      search(root->left,key);
    }
    else if(key>root->data){
        search(root->right,key);
    }
    else{
        cout<<"key found"<<root->data;;
    }
}
int count(node*root){
    if(root==NULL){
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}
 /* count iterative
int countNodesIterative(node* root) {
    if (root == NULL) return 0;

    stack<node*> st;
    st.push(root);
    int count = 0;

    while (!st.empty()) {
        node* temp = st.top();
        st.pop();
        count++;

        if (temp->left) st.push(temp->left);
        if (temp->right) st.push(temp->right);
    }

    return count;
}*/
int countleaves(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return countleaves(root->left)+countleaves(root->right);
}
/* leaves count iterartive
int countLeavesIterative(node* root) {
    if (root == NULL) return 0;

    stack<node*> st;
    st.push(root);
    int count = 0;

    while (!st.empty()) {
        node* temp = st.top();
        st.pop();

        if (temp->left == NULL && temp->right == NULL)
            count++;

        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
    }

    return count;
}*/
int countinternalnodes(node*root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 0;
    }
    return countinternalnodes(root->left)+countinternalnodes(root->right)+1;
}
/*
int countInternalIterative(node* root) {
    if (root == NULL)
        return 0;

    stack<node*> st;
    st.push(root);
    int count = 0;

    while (!st.empty()) {
        node* temp = st.top();
        st.pop();

        // Check if internal node (NOT leaf)
        if (!(temp->left == NULL && temp->right == NULL)) {
            count++;
        }

        if (temp->right != NULL)
            st.push(temp->right);

        if (temp->left != NULL)
            st.push(temp->left);
    }

    return count;
}*/
void displayleafnodes(node*root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL&& root->right==NULL){
        cout<<root->data<<" ";
    }
    displayleafnodes(root->left);
    displayleafnodes(root->right);
}
void displayinternalnodes(node*root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL || root->right!=NULL){
        cout<<root->data;
    }
    displayinternalnodes(root->left);
    displayinternalnodes(root->right);
}
node* getis(node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
node* deletenode(node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->data){
        root->left=deletenode(root->left,key);
    }
    else if(key>root->data){
        root->right=deletenode(root->right,key);
    }
    else{
        //equal
        if(root->left==NULL&& root->right==NULL){
            delete root;
            return NULL;
        }
       else if(root->left==NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        else{
            //2 childs
            node* is=getis(root->right);
            root->data=is->data;
            root->right=deletenode(root->right,is->data);
        }
    }
    return root;
}
int height(node* root) {
    if (root == NULL)
        return -1;   

    int left = height(root->left);
    int right = height(root->right);

    return 1 + max(left, right);
}
/* iterative height
int heightIterative(node* root) {
    if (root == NULL)
        return -1;   // or 0 depending on definition

    queue<node*> q;
    q.push(root);

    int height = -1;

    while (!q.empty()) {
        int size = q.size();  // nodes at current level
        height++;

        while (size--) {
            node* temp = q.front();
            q.pop();

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    return height;
}*/
/*height of a node
int height(node* root){
    if(root == NULL)
        return -1;   // if counting edges

    return 1 + max(height(root->left), height(root->right));
}

// Function to find target node and print its height
void findHeightOfNode(node* root, int key){
    if(root == NULL) return;

    if(root->data == key){
        cout << "Height of node " << key << " = " << height(root);
        return;
    }

    findHeightOfNode(root->left, key);
    findHeightOfNode(root->right, key);
}*/
/*
// Function to find height
int height(node* root){
    if(root == NULL)
        return -1;  // edge-based height

    return 1 + max(height(root->left), height(root->right));
}

// Function to print balance factor of all nodes
void printBalanceFactor(node* root){
    if(root == NULL) return;

    int bf = height(root->left) - height(root->right);
    cout << "Node " << root->data << " -> BF = " << bf << endl;

    printBalanceFactor(root->left);
    printBalanceFactor(root->right);
}*/
/*int sum(node* root){
    if(root == NULL)
        return 0;

    return root->data + sum(root->left) + sum(root->right);
}*/
/*  sum of nodes of a subtree
int subtreeSum(node* root, int key){
    if(root == NULL)
        return 0;

    // If this is the node → return full subtree sum
    if(root->data == key){
        return root->data 
             + subtreeSum(root->left, key) 
             + subtreeSum(root->right, key);
    }

    // Otherwise search in left or right
    int left = subtreeSum(root->left, key);
    if(left != 0) return left;

    return subtreeSum(root->right, key);
}*/

/*  delete only the root
node* findMin(node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

node* deleteRoot(node* root){
    if(root == NULL)
        return NULL;

    // Case 1: no child
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }

    // Case 2: one child
    if(root->left == NULL){
        node* temp = root->right;
        delete root;
        return temp;
    }

    if(root->right == NULL){
        node* temp = root->left;
        delete root;
        return temp;
    }

    // Case 3: two children
    node* succ = findMin(root->right);

    root->data = succ->data;

    // delete successor
    root->right = deleteRoot(root->right);

    return root;
}*/
/*
bool isFull(node* root){
    if(root == NULL)
        return true;

    // leaf node
    if(root->left == NULL && root->right == NULL)
        return true;

    // both children present
    if(root->left && root->right)
        return isFull(root->left) && isFull(root->right);

    return false; // one child only
}*/
/* iscomplete
bool isComplete(node* root){
    if(root == NULL) return true;

    queue<node*> q;
    q.push(root);

    bool foundNull = false;

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            foundNull = true;
        }
        else{
            if(foundNull) return false;

            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return true;
}*/
/* is perfect
int countNodes(node* root){
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(node* root){
    if(root == NULL) return -1;  // edge-based height
    return 1 + max(height(root->left), height(root->right));
}

bool isPerfect(node* root){
    int h = height(root);
    int n = countNodes(root);

    return (n == (1 << (h + 1)) - 1);
}*/

/*  parent->left child->right child
void printParentChildren(node* root){
    if(root == NULL)
        return;

    cout << root->data << " -> ";

    // left child
    if(root->left != NULL)
        cout << root->left->data;
    else
        cout << "NULL";

    cout << " -> ";

    // right child
    if(root->right != NULL)
        cout << root->right->data;
    else
        cout << "NULL";

    cout << endl;

    // recursive calls
    printParentChildren(root->left);
    printParentChildren(root->right);
}*/
int main(){
    node*root=NULL;
    int choice,key;
    do{
        cout<<"\n menu driven ";
        cout<<"\n 1.insert ";
        cout<<"\n 2.display ";
        cout<<"\n 3.inorder recursive";
        cout<<"\n 4.preorder recursive";
        cout<<"\n 5.preorder non recursive";
        cout<<"\n 6. level order ";
        cout<<"\n 7.postorder recursive";
        cout<<"\n 8.postorder non recursive";
        cout<<"\n 9.search";
        cout<<"\n 10.count nodes";
        cout<<"\n 11.count leaves";
        cout<<"\n 12.count internal nodes";
        cout<<"\n 13.display leaf nodes";
        cout<<"\n 14.display internal nodes";
        cout<<"\n 15.delete nodes";
        cout<<"\n 16.height of tree";
        cout<<"\n 17.exit";
        cout<<"\n enter choice:";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"enter element for insertion:";
            cin>>key;
            root=insert(root,key);
            break;
            case 2:
            cout<<"\n inorder recursive:";
            inorder(root);
            cout<<endl;
            break;
            case 3:
            cout<<"inorder non recursive:";
            inorderrecu(root);
            cout<<endl;
            break;
            case 4:
            cout<<"preorder recursive:";
            preorderrec(root);
            break;
            case 5:
            cout<<"preorder non recursive:";
            preordernonrec(root);
            break;
            case 6:
            cout<<"level order:";
            levelorder(root);
            break;
            case 7:
            cout<<"postorder recursive:";
            postorderrec(root);
            break;
            case 8:
            cout<<"postorder non recursive:";
            postordernonrec(root);
            break;
            case 9:
            int element;
            cout<<"enter element to be search:";
            cin>>element;
            search(root,element);
            break;
            case 10:
            cout<<"count of nodes:";
            cout<<count(root);
            break;
            case 11:
            cout<<"count of nodes:";
            cout<<countleaves(root);
            break;
            case 12:
            cout<<"count of internal nodes:";
            cout<<countinternalnodes(root);
            break;
            case 13:
            displayleafnodes(root);
            break;
            case 14:
            displayinternalnodes(root);
            break;
            case 15:
            int v;
            cout<<"enter key to be deleted:";
            cin>>v;
           cout<<"deleted node:"<<deletenode(root,v);
            break;
            case 16:
            cout<<"height of tree:";
            cout<<height(root);
            break;
            case 17:
            cout<<"\n exiting";
            break;
            default:
            cout<<"invalid choice!";
            
        }
    } while(choice!=17);
    return 0;
}