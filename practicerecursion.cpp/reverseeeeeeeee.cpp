#include<iostream>
using namespace std;
string reverse(string &s,int i,string &str){
    if(i<0){
        return "";
    }
    str=str+s[i];
    reverse(s,i--,str);
    return str;
}
int main(){
    string s,str="";
    int j=0;
    cout<<"Enter string: "<<endl;
    cin>>s;
    int i=s.length()-1;
    string sol=reverse(s,i,str);
    cout<<sol;
     
}