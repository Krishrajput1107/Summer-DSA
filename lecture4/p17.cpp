#include<iostream>
using namespace std;
int main(){
    int i,n,j;
    char k=65;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(i=64+n;i>=65;i--){
        for(j=64+n;j>=i;j--){
            cout<<char(j)<<" ";
        }
        cout<<endl;
    }
}