#include<iostream>
#include<string>
using namespace std;

void replacefun(string s){
    string ans = "";
    for(int i=0;i<s.size();i++){
        if(s[i] != ' '){
            ans+=s[i];
        }
        else{
            ans+="@40";
        }
    }
    cout<<ans<<endl;
}
int main(){
    string s;
    cout<<"Enter any string: "<<endl;
    cin>>s;
    getline(cin,s);
    replacefun(s);
    return 0;
}