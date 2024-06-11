#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
void removeadjduplicate(string s){
    stack<char> st;
    for(auto ch:s){
        if(!st.empty() && st.top()==ch){
            st.pop();
        }
        else{
            st.push(ch);
        }
    }
    string ans;
    while(!st.empty()){
        ans=ans+st.top();
        st.pop();
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
}
int main(){
    string s;
    cout<<"Enter string: "<<endl;
    getline(cin,s);
    removeadjduplicate(s);
    
}