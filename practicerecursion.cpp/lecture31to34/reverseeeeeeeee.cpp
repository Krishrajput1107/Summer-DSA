#include<iostream>
#include<vector>
using namespace std;
void reverse(string &s,int i){
    if(i>s.length()){
        return;
    }
    swap(s[i],s[s.length()-i-1]);
    i++;
    reverse(s,i);
}
int main(){
    string s;
    cout<<"Enter string: "<<endl;
    cin>>s;
    int i=0;
    reverse(s,i);
    cout<<s;
     
}