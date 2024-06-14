#include<iostream>
using namespace std;
int main(){
    int arr[10]={2,5,6};
    cout<<"Address of first block is: "<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<"Address of first block is: "<<&arr[0]<<endl;

    cout<<"4th: "<<*arr<<endl;
    cout<<"5th: "<<*arr+1<<endl;
    cout<<"value at first location: "<<*(arr+1)<<endl;
    cout<<"7th: "<<(*arr)+1<<endl;
}