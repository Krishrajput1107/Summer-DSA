#include<iostream>
#include<array>
using namespace std;
bool search(int arr[][4],int row,int col,int target){
        int rowIndex=0;
        int colIndex=col-1;
        while((rowIndex<row)&&(colIndex>=0)){
            int element=arr[rowIndex][colIndex];
            if(target==element){
                return 1;
            }
            if(target<element){
                colIndex--;
            }
            else{
                rowIndex++;
            }
        }

        return 0;
    }

int main(){
    int arr[3][4];
    int target;
    cout<<"Enter elements in array: "<<endl;
    //taking input row-wise
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter element to be searched:"<<endl;
    cin>>target;
    bool ans=search(arr,3,4,target);
    if(ans){
        cout<<"Elememt is present"<<endl;
    }
    else{
        cout<<"Not present"<<endl;
    }
}