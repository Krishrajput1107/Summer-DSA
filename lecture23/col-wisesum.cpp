#include<iostream>
#include<array>
using namespace std;
void colwisesum(int arr[][4],int m,int n){
    int sum;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=0;j<m;j++){
            sum=sum+arr[j][i];
        }
        cout<<"Sum of "<<i<<"th col : "<<sum<<endl;
    }
}

int main(){
    int arr[3][4];
    cout<<"Enter elements in array: "<<endl;
    //taking input row-wise
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cin>>arr[j][i];
        }
    }
    colwisesum(arr,3,4);
}