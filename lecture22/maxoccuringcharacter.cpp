#include<iostream>
#include<string>
#include<vector>
using namespace std;
char getmaxoccuringelement(string s){
    int number=0;
    int arr[26]={0};
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        number=ch-'a';
        arr[number]++;
    }
    int maxi=-1,ans=0;
    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            ans=i;
            maxi=arr[i];
        }
    }
    char finalans=ans+'a';
    return finalans;
}


int main(){
    string s;
    cout<<"Enter any string:"<<endl;
    getline(cin,s);
    char answer=getmaxoccuringelement(s);
    cout<< answer <<endl;
}