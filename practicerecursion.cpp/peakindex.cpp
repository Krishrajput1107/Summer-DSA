#include<iostream>
using namespace std;
int peakelementIndex(int arr[],int s,int e){
    if(s==e){
        return s;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]<arr[mid+1]){
        return peakelementIndex(arr,mid+1,e);
        
    }
    else{
        return peakelementIndex(arr,s,mid);
        
    }
    mid=s+(e-s)/2;
}
int main(){
    int size;
    cout<<"Enter teh size of the array: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter elements in array"<<endl;
    int s=0;
    int e=size-1;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int ans=peakelementIndex(arr,s,e);
    cout<<"Index of peak element is: "<<ans;
}