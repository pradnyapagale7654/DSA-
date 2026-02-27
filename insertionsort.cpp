#include<iostream>
#include<algorithm>
using namespace std;
class solution{
    int arr[100];
    int n;
    public:
    void input(){
        cout<<"enter the size of am array:"<<endl;
        cin>>n;
        cout<<"enter the array elements:";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    }
    void insertion(){
        for(int i=0;i<n;i++){
            int key=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
            j--;}
       arr[j+1]=key;
        }
    }
    void display(){
        cout<<"sorted array is:";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" "<<endl;
        }
    }
};
int main(){
    solution s;
    s.input();
    s.insertion();
    s.display();
    return 0;
}