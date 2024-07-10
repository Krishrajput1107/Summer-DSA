#include<iostream>
#include<stack>
using namespace std;
bool isValidParenthesis(string &expression){
    stack<char> s;
    for(int i=0;i<expression.length();i++){
        char ch=expression[i];

        //if opening bracket stack mae push
        //if closing bracket check top element and pop

        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }

        else{
            //closing bracket hai
            if(!s.empty()){
                char top=s.top();
                if((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='[')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return s.empty();
}


int main(){

    string expression="{([])}";
    bool ans=isValidParenthesis(expression);
    if(ans){
        cout<<"It is balanced "<<endl;
    }
    else{
        cout<<"It is not balanced "<<endl;
    }

}