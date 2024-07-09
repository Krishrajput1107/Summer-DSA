#include<iostream>
#include<stack>
using namespace std;

bool redundantBracket(string &s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%'){
            st.push(ch);
        }

        //It is closing bracket or lower case character
        else{
            bool isRedundant=true;
            if(ch==')'){
                while(st.top()!='('){
                    char top=st.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/' || top=='%'){
                        isRedundant=false;
                    }
                    st.pop();
                }
                st.pop();
                if(isRedundant){
                    return true;
                }
            }    
        }
    }
    return false;
}


int main(){
    string s="((a+b))";
    bool ans=redundantBracket(s);
    cout<<ans;
}