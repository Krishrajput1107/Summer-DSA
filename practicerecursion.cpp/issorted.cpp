#include<iostream>
using namespace std;
bool isSorted(int arr[],int size){
    if((size==0) || (size==1)){
        return 1;
    }
    if(arr[0]>arr[1]){
        return 0;
    }
    else{
        return isSorted(arr+1,size-1);
    }

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
    bool ans=isSorted(arr,size);
    if(ans){
        cout<<"array is sorted";
    }   
    else{
        cout<<"not sorted";
    }
}
