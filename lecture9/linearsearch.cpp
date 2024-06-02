#include<iostream>
using namespace std;
bool LinearSearch(int arr[] , int size){
    int x;
    cout<<"Enter the value to be searched"<<endl;
    cin>>x;
    for(int i=0;i<size;i++){
        if(x==arr[i]){
            return true;
        }
    }
    return false;
}

int main(){
    int size;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the numbers in array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    bool y=LinearSearch(arr,size);
    if(y){
        cout<<"Value is present in the array"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }

}