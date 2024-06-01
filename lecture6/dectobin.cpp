#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int bit,ans=0,n,i=0,ans1=0;
    cout<<"Enter any number"<<endl;
    cin>>n;
    while(n>0){
        bit=n&1;
        ans=(pow(10,i)*bit)+ans;
        n=n>>1;
        i++;
    }
    cout<<ans<<endl;
}