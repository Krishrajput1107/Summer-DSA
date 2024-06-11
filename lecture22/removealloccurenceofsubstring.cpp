#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s,part;
    cout<<"Enter any string: "<<endl;
    getline(cin,s);
    cout<<"Enter part:"<<endl;
    cin>>part;
    removesubstring(s,part);
}