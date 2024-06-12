#include<iostream>
using namespace std;
bool isPresent(int arr[][4], int target , int m ,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int arr[3][4];
    cout<<"Enter elements in array: "<<endl;
    //taking input row-wise
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Enter target element: "<<endl;
    int target;
    cin>>target;

    if(isPresent(arr,target,3,4)){
        cout<<"element presnt"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
}