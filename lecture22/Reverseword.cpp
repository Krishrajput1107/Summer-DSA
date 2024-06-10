#include<iostream>
#include<vector>
#include<string>
using namespace std;
string reverse(string w){
    int s=0;
    int e=w.size()-1;
    while(s<e){
        swap(w[s],w[e]);
        s++;
        e--;
    }
    return w;
} 
int main(){
    string s;
    string w="";
    string temp="";
    cout<<"Enter any sentence: "<<endl;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i] == ' '){
            temp=temp+reverse(w)+" ";
            w="";
        }
        else{
            w=w+s[i];
        }
    }
    for(int i=s.size()-1;s[i]>' ';i--){
            temp=temp+s[i];
    }
    cout<<temp;
    
}