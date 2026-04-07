#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
class node{
    public:
node*left;
node*right;
string key;
string val;
node(string k,string v){
    left=right=NULL;
    key=k;
    val=v;
}
};
node*insert(node*root,string key,string val){
    node*nn=new node (key,val);
    if(root==NULL){
        return nn;
    }
    if(key<root->key){
       root->left=insert(root->left,key,val);
    }
    else if(key>root->key){
        root->right=insert(root->right,key,val);
    }
    else{
        //equal
        root->val=val;
    }
    return root;
}
void search(node*root,string key){
    if(root==NULL){
        cout<<"word not found";
        return;
    }
    if(root->key==key){
        cout<<"found:"<<root->key<<":"<<root->val;
        return;
    }
    if(key<root->key){
        search(root->left,key);
    }
    else{
        search(root->right,key);
    }
}
node*getis(node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
node*deletew(node*root,string key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->key){
        root->left=deletew(root->left,key);
    }
    else if(key>root->key){
        root->right=deletew(root->right,key);
    }
    else{
        //if no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //one child
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
        // both child
        node*is=getis(root->right);
        root->key=is->key;
        root->val=is->val;
        root->right=deletew(root->right,is->key);
    }
    return root;
}
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->key<<":"<<root->val;
    inorder(root->right);
}
node*mirror(node*root){
    if(root==NULL){
        return NULL;
    }
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
    return root;
}
node*copy(node*root){
    if(root==NULL){
        return NULL;
    }
    node*nn=new node(root->key,root->val);
    nn->left=copy(root->left);
    nn->right=copy(root->right);
    return nn;
}
void levelwise(node*root){
    if(root==NULL){
        return ;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        cout<<temp->key<<":"<<temp->val;
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}
void inorderrecursive(node*root){
    stack<node*>st;
    node*curr=root;
    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        node*temp=st.top();
        st.pop();
        cout<<temp->key<<":"<<temp->val;
        curr=temp->right;
    }
}
void preorderrecursive(node*root){
    if(root == NULL)
        return;
        stack<node*>st;
        st.push(root);
        while(!st.empty()){
            node*temp=st.top();
            st.pop();
            cout<<temp->key<<":"<<temp->val;
            if(temp->right!=NULL){
                st.push(temp->right);
            }
            if(temp->left!=NULL){
                st.push(temp->left);
            }
        }
}
void postorderrecursive(node*root){
    if(root==NULL){
        return;
    }
    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);
    while(!s1.empty()){
        node*temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left!=NULL){
            s1.push(temp->left);
        }
        if(temp->right!=NULL){
            s1.push(temp->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->key<<":"<<s2.top()->val;
        s2.pop();
    }
}
void levelorderrecursive(node*root){
    if(root == NULL){
        return;}
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node*temp=q.front();
            q.pop();
            cout<<temp->key<<":"<<temp->val;
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
}
int main(){
    string key,val;
    int choice;
    node*root=NULL;
    node*root2=NULL;
    do{
        cout<<"\n assi 1\n";
        cout<<"\n 1.insert \n";
        cout<<"\n 2.search \n";
        cout<<"\n 3.delete \n";
        cout<<"\n 4.inorder \n";
        cout<<"\n 5.mirror \n";
        cout<<"\n 6.copy \n";
        cout<<"\n 7.levelwise \n";
        cout<<"\n 8.inorder recursive \n";
        cout<<"\n 9.preorder recursive \n";
        cout<<"\n 10.postorder recursive \n";
        cout<<"\n 11.levelorder recursive \n";
        cout<<"0. Exit\n";
        cout<<"enter choice:";
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Enter Word : ";
            cin>>key;
            cout<<"enter meaning:";
            cin>>val;
            root=insert(root,key,val);
            break;
      case 2:
           cout<<"enter key to be searched:";
           cin>>key;
           search(root,key);
            break;
      case 3:
           cout<<"enter key to be deleted:";
           cin>>key;
           root=deletew(root,key);
            break;
     case 4:
           inorder(root);
            break;
     case 5:
           mirror(root);
            break;
    case 6:
           root2=copy(root);
            break;
    case 7:
           levelwise(root);
            break;
    case 8:
           inorderrecursive(root);
            break;
    case 9:
           preorderrecursive(root);
            break;
    case 10:
           postorderrecursive(root);
            break;
    case 11:
           levelorderrecursive(root);
            break;
     case 0:
            cout<<"Exiting...\n";
            break;
     default:
            cout<<"Invalid Choice\n";
        }
    } while(choice != 0);
    return 0;
}