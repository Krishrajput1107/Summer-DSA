#include<iostream>
using namespace std;
int main(){
    int num=5;
    cout<<num<<endl;
    //address of num &
    cout<<"Address of num is: "<< &num <<endl;
    int *ptr=&num;
    cout<<"value is: "<<*ptr<<endl;
    cout<<"Address is: "<<ptr<<endl;

    double d=4.2;
    double *p2=&d;
    cout<<"value is: "<<*p2<<endl;
    cout<<"Address is: "<<p2<<endl;

    cout<<"Size of integer is: "<<sizeof(num)<<endl;
    cout<<"Size of pointer is: "<<sizeof(ptr)<<endl;
    cout<<"Size of pointer is: "<<sizeof(p2)<<endl;

}