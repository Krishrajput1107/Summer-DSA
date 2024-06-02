#include<iostream>
using namespace std;
int nfact(int n){
    int i,f=1;
    for(i=1;i<=n;i++){
        f=f*i;
    }
    return f;
}
int rfact(int r){
    int i,f=1;
    for(i=1;i<=r;i++){
        f=f*i;
    }
    return f;
}
int nrfact(int a){
    int i,f=1;
    for(i=1;i<=a;i++){
        f=f*i;
    }
    return f;
}
int main(){
    int n,r;
    cout<<"Enter the value of n and r "<<endl;
    cin>>n>>r;
    int nf=nfact(n);
    int rf=rfact(r);
    int a=n-r;
    int nrf=nrfact(a);
    double result=nf/(rf*nrf);
    cout<<"result is "<<result;

}