#include<iostream>
#include<array>
using namespace std;
void rotate(int arr[][3],int m,int n){
    for(int col=0;col<n;col++){
        for(int row=m-1;row>=0;row--){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[3][3];
    cout<<"Enter elements in array: "<<endl;
    //taking input row-wise
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    rotate(arr,3,3);
}