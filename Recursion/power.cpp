#include<iostream>
#include<math.h>
using namespace std;
int power(int n){
    if(n==0){
        return 1;
    }
    return 2*power(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<< "Power of "<< n << " is ";
    int ans=power(n);  
    cout<<ans;
}