#include<iostream>
#include<vector>
using namespace std;
int count(int n){
    int cnt=0;
    vector<bool> prime(n+1,true);
    for(int i=2;i<n;i++){
        if(prime[i]){
            cnt++;
        }
        for(int j=2*i;j<n;j=j+i){
            prime[j]=false;
        }
    }
    return cnt;

}

int main(){
    int n;
    cout<<"Enter any number"<<endl;
    cin>>n;
    int ans=count(n);
    cout<<"Prime numbers are: "<<ans<<endl;


}