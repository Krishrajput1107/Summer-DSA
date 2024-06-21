#include<iostream>
#include<vector>
using namespace std;
string reverse(string &s,int i,vector<string> &str){
    if(i<0){
        return "";
    }
    str=str.push_back(s[i]);
    reverse(s,i--,str);
    return str;
}
int main(){
    string s;
    vector<string> str;
    int j=0;
    cout<<"Enter string: "<<endl;
    cin>>s;
    int i=s.length()-1;
    vector<string>str sol=reverse(s,i,str);
    cout<<sol;
     
}