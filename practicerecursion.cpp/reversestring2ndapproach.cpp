#include<iostream>
using namespace std;
string reverseHelper(string &s,int i){
    if(i<0){
        return "";
    }
    i--;
    return s[i]+reverseHelper(s,i);
}

string reverseString(string &s) {
    return reverseHelper(s, s.size() - 1);
}
int main(){
    string s;
    cout<<"Enter string: "<<endl;
    cin>>s;
    int i=s.size()-1;
    cout<<endl;
    string sol=reverseString(s);
    cout<<endl; 
    cout<<sol;
     
}