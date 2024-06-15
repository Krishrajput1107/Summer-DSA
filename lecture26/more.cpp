#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    char ch[6]="abcde";
    cout<< arr<<endl;
    cout<< ch <<endl;
    //attention here
    char *c= &ch[0];
    //print entire characters
    cout<< c <<endl;

    char temp='z';
    char *p= &temp;
    cout<<p<<endl;

    char tem='s';
    char *ptr= &tem;
    cout<<ptr<<endl;
}