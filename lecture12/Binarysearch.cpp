#include<iostream>
using namespace std;
int binarySearch(int arr[],int size){
    int x;
    cout<<"Enter the element to be searched: "<<endl;
    cin>>x;
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==x){
            return mid;
        }
        else if(x>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
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
   int idx=binarySearch(arr,size);
   cout<<"Index of element is: "<<idx<<endl;
}