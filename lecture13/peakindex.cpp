#include<iostream>
using namespace std;
int peakelementIndex(int arr[],int size){
    int s=0,e=size-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return mid;
}
int main(){
    int size;
    cout<<"Enter teh size of the array: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter elements in array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int ans=peakelementIndex(arr,size);
    cout<<"Index of peak element is: "<<ans;
}