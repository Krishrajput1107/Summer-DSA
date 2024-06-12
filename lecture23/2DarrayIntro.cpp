#include<iostream>
using namespace std;
int main(){
    int arr[3][4];
    cout<<"Enter elements in array: "<<endl;
    //taking input row-wise
    /*for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    */
   //taking input column wise
   for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cin>>arr[j][i];
        }
    }
    cout<<"2D array is: "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}