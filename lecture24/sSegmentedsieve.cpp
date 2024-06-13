#include<iostream>
#include<vector>
using namespace std;
void Segmentedsieve(int n){
    int cnt=0;
    vector<bool> prime(n+1,true);
    for(int i=2;i<n;i++){
        if(prime[i]){
            cout<<i<<" ";
        }
        for(int j=2*i;j<n;j=j+i){
            prime[j]=false;
        }
    }

}

int main(){
    int n;
    cout<<"Enter any number"<<endl;
    cin>>n;
    Segmentedsieve(n);
}