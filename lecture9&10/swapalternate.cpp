#include<iostream>
using namespace std;
int swapalternate(int arr[], int size){
    int s=0,e=s+1;
    while(e<size){
        swap(arr[s],arr[e]);
        s=s+2;
        e=e+2;
    }
}
int printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    swapalternate(arr,size);
    printarray(arr,size);
    
}