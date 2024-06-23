#include<iostream>
using namespace std;
void bubblesort(int arr[],int size){
    //base case
    if(size==0 || size==1){
        return;
    }
    //recursive case
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubblesort(arr,size-1);
}
int main(){
    int size;
    cout<<"Enter size: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    bubblesort(arr,size);   
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}