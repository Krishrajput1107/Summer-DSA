#include<iostream>
using namespace std;
int main(){
    int n,i,c=0;
    cout<<"Enter the value of n "<<endl;
    cin>>n;
    for(i=2;i<n;i++){
        if(n%i==0){
            c++;
            break;
        }
    }
    if(c>0){
        cout<<"It's not a prime number"<<endl;
    }
    else{
        cout<<"It's a prime number"<<endl;
    }
}