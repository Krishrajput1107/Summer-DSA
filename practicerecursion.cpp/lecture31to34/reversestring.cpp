#include<iostream>
using namespace std;
void reverse(string &s,int i,int j){
    cout<<"call received for "<<s<<endl;
    if(i>j){
        return;
    }
    swap(s[i],s[j]);
    i++;
    j--;
    return reverse(s,i,j);
}
int main(){
    string s;
    cout<<"Enter string: "<<endl;
    cin>>s;
    int i=0;
    int j=s.size()-1;
    cout<<endl;
    reverse(s,i,j);
    cout<<endl; 
    cout<< s <<endl;  
}