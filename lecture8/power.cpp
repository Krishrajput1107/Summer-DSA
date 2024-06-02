#include<iostream>
using namespace std;
int power(int a, int b){
    int res=1;
    for(int i=1;i<=b;i++){
        res=res*a;
    }
    return res;
}

int main(){
    int a,b,p;
    cout<<"Enter the value of a and b"<<endl;
    cin>>a;
    cin>>b;
    p=power(a,b);
    cout<<"Result is "<< p <<endl;

}