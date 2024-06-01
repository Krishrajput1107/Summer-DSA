#include<iostream>
using namespace std;
int main(){
    int a=0,b=1,temp,n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    cout<<a<<" ";
    cout<<b<<" ";
    for(int i=1;i<=n-2;i++){
        temp=a+b;
        cout<<temp<<" ";
        a=b;
        b=temp;
    }
}