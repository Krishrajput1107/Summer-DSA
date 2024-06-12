#include<iostream>
#include<array>
using namespace std;
void rowwisesum(int arr[][4],int m,int n){
    int sum;
    for(int i=0;i<m;i++){
        sum=0;
        for(int j=0;j<n;j++){
            sum=sum+arr[i][j];
        }
        cout<<"Sum of "<<i<<"th row : "<<sum<<endl;
    }
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
    rowwisesum(arr,3,4);
}