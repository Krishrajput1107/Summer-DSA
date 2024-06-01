#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int digit=0,n,ans=0,i=0;
    cout<<"Enter any number"<<endl;
    cin>>n;
    while(n!=0){
        digit=n%10;
        if(digit==1){
            ans=ans+pow(2,i);
        }
        n=n/10;
        i++;
    }
    cout<<"Answer is:"<<ans; 
}