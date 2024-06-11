#include<iostream>
#include<string>
#include<vector>
using namespace std;
void removesubstring(string s,string part){
    while(s.length()!=0 && part.length()<s.length()){
        s.erase(s.find(part),part.length());
    }
    cout<<"Answer after removing substring: "<<s;
}
int main(){
    string s,part;
    cout<<"Enter any string: "<<endl;
    getline(cin,s);
    cout<<"Enter part:"<<endl;
    cin>>part;
    removesubstring(s,part);
}