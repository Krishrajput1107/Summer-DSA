#include<iostream>
using namespace std;
int main(){
    int i,n,j;
    char ch=65;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}