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
}