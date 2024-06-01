#include<iostream>
using namespace std;
int main(){
    int i,n,j;
    char k;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    for(i=65;i<=64+n;i++){
        k=i;
        for(j=65;j<=64+n;j++){
            cout<<char(k)<<" ";
            k++;
        }
        cout<<endl;
    }
}