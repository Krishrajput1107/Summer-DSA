#include<iostream>
using namespace std;
int uniqueelement(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    cout<<"Unique element is: "<<ans;
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
    uniqueelement(arr,size);
}