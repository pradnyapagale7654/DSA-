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
    int score;
    int player_id;
    int height;

    node(int v,int k){
        player_id=v;
        score=k;
        height=1;
        left=right=NULL;
    }
};


// Height
int height(node*root){
    if(root==NULL)
        return 0;
    return root->height;
}


// Balance factor
int getbalance(node*root){
    if(root==NULL)
        return 0;
    return height(root->left)-height(root->right);
}


// Right Rotation (LL)
node*rightrotate(node*z){

    node*y=z->left;
    node*t3=y->right;

    y->right=z;
    z->left=t3;

    z->height=max(height(z->left),height(z->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}


// Left Rotation (RR)
node*leftrotate(node*z){

    node*y=z->right;
    node*t2=y->left;

    y->left=z;
    z->right=t2;

    z->height=max(height(z->left),height(z->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}


// Insert
node*insert(node*root,int player_id,int score){

    if(root==NULL)
        return new node(player_id,score);

    if(score<root->score)
        root->left=insert(root->left,player_id,score);

    else if(score>root->score)
        root->right=insert(root->right,player_id,score);

    else{
        cout<<"Duplicate score not allowed\n";
        return root;
    }

    root->height=1+max(height(root->left),height(root->right));

    int balance=getbalance(root);

    // LL
    if(balance>1 && score<root->left->score)
        return rightrotate(root);

    // RR
    if(balance<-1 && score>root->right->score)
        return leftrotate(root);

    // LR
    if(balance>1 && score>root->left->score){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }

    // RL
    if(balance<-1 && score<root->right->score){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}


// Inorder Successor
node*getis(node*root){

    while(root->left!=NULL)
        root=root->left;

    return root;
}


// Delete
node*deletew(node*root,int score){

    if(root==NULL)
        return NULL;

    if(score<root->score)
        root->left=deletew(root->left,score);

    else if(score>root->score)
        root->right=deletew(root->right,score);

    else{

        // No child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // One child
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

        // Two children
        node*is=getis(root->right);

        root->score=is->score;
        root->player_id=is->player_id;

        root->right=deletew(root->right,is->score);
    }


    // Update height
    root->height=1+max(height(root->left),height(root->right));


    int balance=getbalance(root);

    // LL
    if(balance>1 && getbalance(root->left)>=0)
        return rightrotate(root);

    // LR
    if(balance>1 && getbalance(root->left)<0){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }

    // RR
    if(balance<-1 && getbalance(root->right)<=0)
        return leftrotate(root);

    // RL
    if(balance<-1 && getbalance(root->right)>0){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}


// Leaderboard (Descending Order)
void leaderboard(node*root){

    if(root==NULL)
        return;

    leaderboard(root->right);

    cout<<"Player ID : "<<root->player_id
        <<" Score : "<<root->score<<endl;

    leaderboard(root->left);
}



int main(){

node*root=NULL;

int score,player_id;
int choice;

do{

cout<<"\n------ Multiplayer Game ------\n";
cout<<"1. Player Registration\n";
cout<<"2. Remove Player\n";
cout<<"3. Leaderboard\n";
cout<<"0. Exit\n";

cout<<"Enter choice: ";
cin>>choice;

switch(choice){

case 1:
cout<<"Enter Player ID: ";
cin>>player_id;

cout<<"Enter Score: ";
cin>>score;

root=insert(root,player_id,score);
break;

case 2:
cout<<"Enter Score to Delete: ";
cin>>score;

root=deletew(root,score);
break;

case 3:
cout<<"\nLeaderboard\n";
leaderboard(root);
break;

case 0:
cout<<"Exiting...\n";
break;

default:
cout<<"Invalid choice\n";

}

}while(choice!=0);

return 0;
}