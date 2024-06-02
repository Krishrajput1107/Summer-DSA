#include<iostream>
using namespace std;
int power(){
    int a,b;
    cin>>a>>b;
    int res=1;
    for(int i=1;i<=b;i++){
        res=res*a;
    }
    return res;
}

int main(){
    int a,b,p;
    cout<<"Enter the value of a and b"<<endl;
    p=power();
    cout<<"Result is "<< p <<endl;

}