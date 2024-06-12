#include<iostream>
#include<array>
#include<vector>
using namespace std;
vector<int> wave(int arr[][4],int m,int n){
    vector<int> ans;
    for(int col=0;col<n;col++){
        if(col&1){
            //printing bottome to up
            for(int row=m-1;row>=0;row--){
                cout<<arr[row][col]<<" ";
                ans.push_back(arr[row][col]);
            }
            cout<<endl;
        }
        else{
            //printing up to bottom
            for(int row=0;row<m;row++){
                cout<<arr[row][col]<<" ";
                ans.push_back(arr[row][col]);
            }
            cout<<endl;
        }
    }
    return ans;
    
}

int main(){
    int arr[3][4];
    cout<<"Enter elements in array: "<<endl;
    //taking input row-wise
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }
    
    vector<int> answer=wave(arr,3,4);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}