#include<iostream>
#include<string>
using namespace std;

string stringReplace(string s){

    string temp = "";

    for(int i = 0; i<s.length(); i++){
        if(s[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
            
        }
        else{
            temp.push_back(s[i]);
        }
    }
    return temp;
}


int main() {

    string s;
    getline(cin,s);

    string ans=stringReplace(s);

    cout<<ans<<endl;

    return 0;

}