#include<iostream>
using namespace std;
void reverse(char name[], int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(name[s],name[e]);
        s++;
        e--;
    }
}
int getLength(char name[]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }
    return count;
}
int main(){
    char name[20];
    cout<<"Enter your names"<<endl;
    cin>>name;
    cout<<"Your name is: ";
    cout<<name<<endl;
    cout<<"Length of your name is: ";
    int len=getLength(name);
    cout<<len<<endl;
    reverse(name,len);
    cout<<"Your name is: ";
    cout<<name<<endl;
}