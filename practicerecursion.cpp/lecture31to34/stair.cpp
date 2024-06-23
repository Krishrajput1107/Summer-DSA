#include<iostream>
using namespace std;
int stair(int n){
    //base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    //recursive case
    int ans=stair(n-1)+stair(n-2);
    return ans;
}
int main(){
    int n;
    cout<<"Enter any number: "<<endl;
    cin>>n;
    int ans=stair(n);
    cout<<ans;
}