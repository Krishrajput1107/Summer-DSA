#include<iostream>
using namespace std;
void reverse(string &s,int i){
    if(i<0){
        return;
    }
    return reverse(s,i--);
}
int main(){
    string s,str="";
    int j=0;
    cout<<"Enter string: "<<endl;
    cin>>s;
    int i=s.size()-1;
    cout<<endl;
    reverse(s,i);
    cout<<s;
     
}