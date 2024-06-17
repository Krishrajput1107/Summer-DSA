#include<iostream>
using namespace std;
bool isSorted(int arr[],int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool ans=isSorted(arr+1,size-1);
        return ans;
    }
}

int main(){
    int size;
    cout<<"Size of array: "<<endl;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }   
    bool ans=isSorted(arr,size);
    cout<<ans;
}