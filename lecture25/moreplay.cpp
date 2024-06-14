#include<iostream>
using namespace std;
int main(){
    int num=5;
    int a=num;
    a++;
    cout<<"before "<<num<<endl;
    int *p=&num;
    (*p)++;
    cout<<"after "<<num<<endl;

    //copying a pointer
    int *q=p;
    cout<< p << "-" << q <<endl;
    cout<< *p << "-" << *q <<endl;

    //important concepts
    int i=3;
    int *t=&i;
    cout<< "before: "<< *t <<endl;
    *t=*t+1;
    cout<<"after: "<< *t <<endl;
    cout<<"before: "<<t <<endl;
    t=t+1;
    cout<<"after: "<< t <<endl;

    double dt=7.99;
    double *dtr=&dt;
    cout<< "before: "<< *dtr <<endl;
    *dtr=*dtr+1;
    cout<<"after: "<< *dtr <<endl;
    cout<<"before: "<<dtr <<endl;
    dtr=dtr+1;
    cout<<"after: "<< dtr <<endl;


}