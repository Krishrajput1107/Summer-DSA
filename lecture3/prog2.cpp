#include<iostream>
using namespace std;
int main(){
    char ch;
    cout<<"enter any character "<<endl;
    cin>>ch;
    if((ch>=48)&&(ch<=57)){
        cout<<"This is numeric value"<<endl;
    }
    else if((ch>=65)&&(ch<=90)){
        cout<<"Upper case character"<<endl;
    }
    else{
        cout<<"Lower case character"<<endl;
    }
}