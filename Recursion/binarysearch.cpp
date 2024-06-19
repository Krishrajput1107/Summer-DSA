#include<iostream>
using namespace std;
bool binSearch(int arr[],int s,int e,int key){
    //base case
    int mid=s+(e-s)/2;
    if(s>e){
        return false;
    }
    if(arr[mid]==key){
        return true;
    }
    if(arr[mid]<key){
        return binSearch(arr,mid+1,e,key);
    }
    else{
        return binSearch(arr,s,mid-1,key);
    }

}

int main(){
    int arr[6]={2,4,9,11,14,16};
    int size=6;
    int key;
    cout<<"Enter key: "<<endl;
    cin>>key;
    int s=0;
    int e=size-1;
    bool ans=binSearch(arr,s,e,key);   
    if(ans){
        cout<<"Presnt"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }
}