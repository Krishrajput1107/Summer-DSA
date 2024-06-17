#include<iostream>
using namespace std;
int distinctway(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans=distinctway(n-1)+distinctway(n-2);
    return ans;
}
int main(){
    int n;
    cout<<"Enter number of stairs: "<<endl;
    cin>>n;   
    int ans=distinctway(n);
    cout<<"Number of ways to climb a stair: "<<ans<<endl;
}