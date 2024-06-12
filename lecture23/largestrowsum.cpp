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
int largestrowsum(int arr[][4], int m, int n){
    int maxi=INT16_MIN;
    int rowIndex=-1;
    int sum;
    for(int i=0;i<m;i++){
        sum=0;
        for(int j=0;j<n;j++){
            sum=sum+arr[i][j];
        }
        if(maxi<sum){
            maxi=sum;
            rowIndex=i;
        }
    }
    cout<<"Largest row sum is: "<<maxi<<endl;
    return rowIndex;

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
    int ans=largestrowsum(arr,3,4);
    cout<<"Largest row is: "<<ans<<endl;
}