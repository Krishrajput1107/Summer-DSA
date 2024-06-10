#include<iostream>
using namespace std;
char toLowercase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char s=ch-'A'+'a';
    }
}
bool checkPalindrome(char a[], int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        if(toLowercase(a[s])!=toLowercase(a[e])){
             return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
int main(){
    char a[20];
    int size=0;
    cout<<"Enter the word: "<<endl;
    cin>>a;
    for(int i=0;a[i]!='\0';i++){
        size++;
    }
    bool c=checkPalindrome(a,size);
    cout<<c;
    
}