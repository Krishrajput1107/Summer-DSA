#include<iostream>
using namespace std;
int duplicatenumber(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    for(int i=1;i<size;i++){
        ans=ans^i;
    }
    return ans;
}
int main(){
    int size;
    cout<<"enter the size of the array: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int p=duplicatenumber(arr,size);
    cout<<"Duplicate number is: "<<p<<endl;
}