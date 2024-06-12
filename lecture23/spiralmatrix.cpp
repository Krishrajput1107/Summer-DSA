#include<iostream>
#include<array>
#include<vector>
using namespace std;
vector<int> spiral(int arr[][4], int m, int n){
    vector<int> ans;
    int startingcol=0;
    int endingcol=n-1;
    int startingrow=0;
    int endingrow=m-1;
    int total=m*n;
    int count=0;
    while(count<total){
        //for starting row
        for(int index=startingcol;count<total && index<=endingcol;index++){
            ans.push_back(arr[startingrow][index]);
            count++;
        }
        startingrow++;
        //for ending column
        for(int index=startingrow;count<total && index<=endingrow;index++){
            ans.push_back(arr[index][endingcol]);
            count++;
        }
        endingcol--;
        //for ending row
        for(int index=endingcol;count<total && index>=startingcol;index--){
            ans.push_back(arr[endingrow][index]);
            count++;
        }
        endingrow--;
        //for starting column
        for(int index=endingrow;count<total && index>=startingrow;index--){
            ans.push_back(arr[index][startingcol]);
            count++;
        }
        startingcol++;
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
    
    vector<int> answer=spiral(arr,3,4);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
}