#include<iostream>
using namespace std;
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
    cout<<len;

}