
#include<iostream>
using namespace std;
class node{
public:
string music;
node*next;
node(){
music=" ";
next=NULL;
}
node(string name){
music=name;
next=NULL;
}
};
class list{
public:

node*head;
list(){
head=NULL;
}
void insert_music_end(string name){
node*newnode=new node(name);
if(head==NULL){
head=newnode;
}
else{
node*temp=head;
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=newnode;
}
}
void insert_music_beg(string name){
node*newnode=new node(name);
if(head==NULL){
head=newnode;
}
else{
newnode->next=head;
head=newnode;
}
}
void insert_bet(string name){
int pos;
cout<<"enter the position where node is to be inserting:";
cin>>pos;
node*newnode=new node(name);
if(head==NULL){
head=newnode;
}
else{
node*temp=head;
for(int i=1;i<pos-1 && temp!=NULL;i++){
temp=temp->next;
}
newnode->next=temp->next;
temp->next=newnode;
}
}
void delete_music_head(){
if(head==NULL){
cout<<"linked list is empty";
}
node* temp = head;
head = head->next;
delete temp;
}
void delete_music_tail(){
if(head==NULL){
cout<<"linked list is empty";
}
node*temp=head;
node*prev=head;
temp=temp->next;
while(temp->next!=NULL){

prev=prev->next;
temp=temp->next;
}
prev->next=NULL;
delete temp;
}
void delete_pos(int pos){

if(head==NULL){
cout<<"list is empty:";
}
else{
node*current=head;
for(int i=1;i<pos-1 && current ; i++){
current=current->next;}
node*temp=current->next;
current->next=temp->next;
delete temp;}
}
void prevSong() {
cout << "Playlist is empty";

string key;
cout << "Enter key: ";
cin >> key;
if (head->music == key) {
cout << "this is first song no previous song";
}
node* prev = head;
node* temp = head->next;
while (temp->music != key) {
prev = temp;
temp = temp->next;
}
cout<< prev->music;
}
void nextSong() {
if (!head) {
cout << "Playlist empty";
}
string key;
cout << "Enter key: ";
cin >> key;
node* temp = head;
while (temp->music != key) {
temp = temp->next;
}
cout<< temp->next->music;
}
void print() {
if (head == NULL) {
cout << "Linked list is empty\n";

}
node* T = head;
while (T != NULL) {
cout << T->music << " "<<endl;
T = T->next;
}
}
};
int main() {
list l;
int choice;
string song;
do {
cout << "\n=== Music Playlist Menu ===\n";
cout << "1. Add song at beginning\n";
cout << "2. Add song at end\n";
cout << "3. Delete song from beginning\n";
cout << "4. Delete song from end\n";
cout << "5. Play next song\n";
cout << "6. Play previous song\n";
cout<< " 7.insert song in between\n";
cout<< "8.delete song at particular position\n";
cout << "9. Show playlist\n";
cout << "10. Exit\n";
cout << "Enter choice: ";
cin >> choice;
switch(choice) {
case 1:
cout << "Enter song name: ";
cin >> song;
l.insert_music_end(song);
break;
case 2:
cout << "Enter song name: ";
cin >> song;
l.insert_music_beg(song);
break;
case 3:
l.delete_music_head();
break;
case 4:
l.delete_music_tail();
break;
case 5:
l.nextSong();
break;

case 6:
l.prevSong();
break;
case 7:
cout << "Enter song name: ";
cin >> song;
l.insert_bet(song);
break;
case 8:
l.delete_pos(3);
break;
case 9:
l.print();
break;
case 10:
cout << "Exiting playlist...\n";
break;
default:
cout << "Invalid choice!\n";
}
} while(choice != 10);
return 0;
}