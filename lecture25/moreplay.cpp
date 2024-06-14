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

}