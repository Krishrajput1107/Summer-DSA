#include<iostream>
using namespace std;
int main(){
    int i,n,j,k=1;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
    }
}