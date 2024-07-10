#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool knows(int arr[][3], int a, int b){
    if(arr[a][b]==1){
        return true;
    }
    else{
        return false;
    }
}

int Celebrity(int arr[][3] , int n){
    stack<int> s;
    //push all elements in stack
    for(int i=0;i<n;i++){
        s.push(i);
    }

    //check krengae
    while(s.size()>1){
        int a=s.top();
        s.pop();

        int b=s.top();
        s.pop();

        if(knows(arr,a,b)){
            s.push(b);
        }

        else{
            s.push(a);
        }
    }
    int ans=s.top();

    //verify all zero in row
    int zeroCount=0;
    for(int i=0;i<n;i++){
        if(arr[ans][i]==0){
            zeroCount++;
        }
    }

    //verify all 1's in col except diagonal=0

    int colCount=0;
    for(int i=0;i<n;i++){
        if(arr[i][ans]==1){
            colCount++;
        }
    }
    if(zeroCount==n && colCount==n-1){
        return ans;
    }

    else{
        return -1;
    }

}

int main(){
    int arr[3][3];
    cout<<"Enter row and column "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    int ans=Celebrity(arr,3);
    cout<<"Celebrity is: "<<ans<<endl;
}