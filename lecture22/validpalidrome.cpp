#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isValid(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')|| (ch>='0' && ch<='9')){
        return 1;
    }
    else{
        return 0;
    }
}
char toLowercase(char ch){
    if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return ch;
    }
    else{
        char s=ch-'A'+'a';
    }
}
bool checkPalindrome(string s){
    int st=0;
    int e=s.length()-1;
    while(st<=e){
        if(s[st]!=s[e]){
            return 0;
        }
    }
    return 1;
}

bool isPalindrome(string s){
    //faaltu character haatao
    string temp="";
    for(int j=0;j<s.length();j++){
        if(isValid(s[j])){
            temp.push_back(j);
        }
    }
    //lower case mae kro
    for(int j=0;j<s.length();j++){
        temp[j]=toLowercase(temp[j]);
    }

    if(checkPalindrome(temp)){
        return 1;
    }
    else{
        return 0;
    }
}



int main(){
    string s;
    cout<<"Enter any string:"<<endl;
    cin>>s;
    bool b=isPalindrome(s);
    if(b){
        cout<<"It is Palindrome"<<endl;
    }
    else{
        cout<<"It is not plaindrome"<<endl;
    }
}
