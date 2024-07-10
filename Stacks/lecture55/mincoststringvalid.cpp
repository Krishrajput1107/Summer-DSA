#include<iostream>
#include<stack>
using namespace std;
int Mincost(string str){
    //odd condition
    int ans=0;
    if(str.length()%2==1){
        return -1;
    }

    //even condition
    stack<int> s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='{'){
            s.push(ch);
        }
        else{
            if(!s.empty() && s.top()=='}'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }
//stack contatin invalid expression
        int a=0,b=0;
        while(!s.empty()){
            char ch=s.top();
            if(ch=='{'){
                b++;
            }
            else{
                a++;
            }
            s.pop();
        }
        ans=(a+1)/2 + (b+1)/2;
    return ans;
}


int main(){
    string str="{{{{}{";
    int ans=Mincost(str);
    cout<<ans;
}
