#include<iostream>
using namespace std;
int main(){
    //point to int is created which is point to any garbage address
    //int *ptr=0;
    //cout<< *ptr <<endl;
    int i=5;
    int *q=&i;
    cout<<"Address is: "<<q<<endl;
    cout<<"Value is: "<<*q<<endl;
    int *p=0;
    p=&i;
    cout<<"Address is: "<<p<<endl;
    cout<<"Value is: "<<*p<<endl;



}