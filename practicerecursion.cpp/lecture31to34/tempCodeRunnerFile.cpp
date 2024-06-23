#include<iostream>
using namespace std;
int Fib(int n){
    //base case
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    //recursive case
    int ans=Fib(n-1)+Fib(n-2);
    return ans;
}
int main(){
    int n;
    cout<<"Enter any number: "<<endl;
    cin>>n;
    int ans=Fib(n);
    cout<<ans;
}