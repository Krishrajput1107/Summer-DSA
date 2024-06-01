#include<iostream>
using namespace std;
int main(){
    int i,n,j,k;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(i=65;i<65+n;i++){
        k=i;
        for(j=65;j<65+n;j++){
            cout<<char(k)<<" ";
            k++;
        }
        cout<<endl;
    }
}