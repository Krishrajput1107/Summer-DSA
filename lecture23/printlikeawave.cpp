#include<iostream>
#include<array>
using namespace std;
void colwisesum(int arr[][4],int m,int n){
    int sum;
    for(int col=0;col<n;col++){
        sum=0;
        for(int row=0;row<m;row++){
            sum=sum+arr[row][col];
        }
        cout<<"Sum of "<<col<<"th col : "<<sum<<endl;
    }
}

int main(){
    int arr[3][4];
    cout<<"Enter elements in array: "<<endl;
    //taking input row-wise
    for(int col=0;col<4;col++){
        for(int row=0;row<3;row++){
            cin>>arr[row][col];
        }
    }
    colwisesum(arr,3,4);
}