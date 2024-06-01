#include<iostream>
using namespace std;
int main(){
    int i,n,j;
    char ch=64;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        ch++;
        for(j=1;j<=i;j++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}