#include<iostream>
 #include<queue> 
 #include<stack>
using namespace std;

struct Node { int data; Node* next;
};

struct Graph
{
int v;
int **adjMatrix;
 Node** adjList;

void Create_Matrix(){
cout<<"Enter number of vertices : "; cin>>v;

adjMatrix = new int*[v];
 for(int i=0;i<v;i++){
adjMatrix[i] = new int[v];
 
}
for(int i=0;i<v;i++){
     for(int j=0;j<v;j++){
adjMatrix[i][j]=0;
}
}
int edges;
cout<<"Enter number of edges : ";
 cin>>edges;

int s,d;
for(int i=0;i<edges;i++){
cout<<"Enter the source and destination : ";
 cin>>s>>d;
adjMatrix[s][d]=1;
 adjMatrix[d][s]=1;
}
}

void create_List() {
cout<<"Enter number of vertices : "; 
cin>>v;
adjList = new Node*[v];
 for(int i=0;i<v;i++){
adjList[i] = NULL;
}
int edges;
cout<<"Enter number of edges : "; 
cin>>edges;

int s,d;
for(int i=0;i<edges;i++){
cout<<"Enter source and destination : ";
 cin>>s>>d;

Node* newNode = new Node();
 newNode->data = d;
 
newNode->next = adjList[s];
 adjList[s] = newNode;

newNode = new Node(); 
newNode->data = s;
 newNode->next = adjList[d];
  adjList[d] = newNode;
}
}

void BFS_Matrix(){ int start;
cout<<"Enter the starting node : ";
 cin>>start;

int *visit = new int[v]{0};

queue<int>q; q.push(start); 
visit[start]=1;

int d; while(!q.empty() ){
d=q.front();
 cout<<d<<" "; 
q.pop();

for(int i=0;i<v;i++){ 
    if(adjMatrix[d][i]==1 && visit[i]==0){
q.push(i); visit[i]=1;
}
}
}
cout<<endl;
}

void BFS_list() {
     int start;
 
cout<<"Enter starting node : "; 
cin>>start;

int *visit = new int[v]{0};

queue<int> q; q.push(start); 
visit[start] = 1;

int d; while(!q.empty()) {
d = q.front();
 cout<<d<<" ";
  q.pop();

Node* temp = adjList[d]; 
while(temp != NULL) {
if(visit[temp->data] == 0) {
     q.push(temp->data); 
     visit[temp->data] = 1;
}
temp = temp->next;
}
}
cout<<endl;
}

void DFS_Matrix(){ 
    int start;
cout<<"Enter the starting node : ";
 cin>>start;
int *visit = new int[v]{0}; 
stack<int>s;
s.push(start);
visit[start]=1; 
int d;
 
while(!s.empty()){
     d=s.top(); 
     cout<<d<<" "; 
     s.pop();

for(int i=0;i<v;i++){
     if(adjMatrix[d][i]==1 && visit[i]==0){
s.push(i);
 visit[i]=1;
}
}
}
cout<<endl;
}

void DFS_list() { 
    int start;
cout<<"Enter starting node : ";
 cin>>start;

int *visit = new int[v]{0};

stack<int> s; s.push(start);
 visit[start] = 1;

int d; while(!s.empty()) {
d = s.top();
 cout<<d<<" "; 
 s.pop();

Node* temp = adjList[d];
 while(temp != NULL) {
if(visit[temp->data] == 0) {
     s.push(temp->data); 
     visit[temp->data] = 1;
}
temp = temp->next;
 
}
}
cout<<endl;
}
};

int main(){
 int choice;
  int v1;
Graph g;
 do{
cout<<"	"<<endl;
cout<<"1] Create maze using adj. matrix "<<endl;
cout<<"2] Create maze using adj. list "<<endl;
cout<<"3] DFS for matrix"<<endl;
cout<<"4] DFS for list"<<endl; 
cout<<"5] BFS for matrix"<<endl; 
cout<<"6] BFS for list"<<endl; 
cout<<"7] Exit"<<endl;
cout<<"	"<<endl;
cout<<"Enter choice : "; 
cin>>choice;
cout<<"	"<<endl;

switch(choice){
     case 1:
g.Create_Matrix(); break;
case 2: g.create_List(); break;
case 3: g.DFS_Matrix(); break;
case 4: g.DFS_list(); break;
case 5:
 
g.BFS_Matrix(); break;
case 6:
g.BFS_list(); break;
case 7: cout<<"Exiting..."<<endl; break;
default:
cout<<"Enter the valid choice."<<endl;
}
}while(choice != 7);
return 0;
}
