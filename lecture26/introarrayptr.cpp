#include<iostream>
using namespace std;
int main(){
    int arr[10]={23,122,48,67};
    cout<<"Address of first block is: "<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<"Address of first block is: "<<&arr[0]<<endl;

    cout<<"4th: "<<*arr<<endl;
    cout<<"5th: "<<*arr+1<<endl;
    cout<<"value at first location: "<<*(arr+1)<<endl;
    cout<<"7th: "<<(*arr)+1<<endl;
    cout<<"8th: "<<arr[2]<<endl;
    cout<<"9th: "<<*(arr+2)<<endl;

    int i=3;
    cout<<i[arr]<<endl;

    int temp[10];
    int *ptr=&temp[0];
    cout<<"Size of array: "<<sizeof(temp)<<endl;
    cout<<"Size of pointer: "<< sizeof(ptr)<<endl;

}