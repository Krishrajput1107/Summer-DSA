#include<iostream>
using namespace std;
void print(int arr[], int size){
    cout<<endl;
    cout<<"Size of array is: "<<size<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool linearSearch(int arr[],int size,int key){
    print(arr,size);
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    linearSearch(arr+1,size-1,key);
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
    int key;
    cout<<"Enter element to be searched: "<<endl;
    cin>>key;
    bool ans=linearSearch(arr,size,key);   
    if(ans){
        cout<<"element is present"<<endl;
    }
    else{
        cout<<"element is not present"<<endl;
    }
}