#include<iostream>
using namespace std;
int firstocc(int arr[],int size,int key){
    int ans=-1;
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
    int lastocc(int arr[],int size,int key){
    int ans=-1;
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    cout<<"Enter the size of the array"<<endl;
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in the array: "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter key: "<<endl;
    cin>>key;
   int idx=firstocc(arr,size,key);
   int lidx=lastocc(arr,size,key);
   cout<<"first Index of  element is: "<<idx<<endl;
   cout<<"last Index of  element is: "<<lidx<<endl;
}