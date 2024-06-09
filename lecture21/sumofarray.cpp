#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v) {
    
    int s = 0;
    int e = v.size()-1;
    
    while(s<e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	
    int i = n-1;
    int j = m-1;
    vector<int> ans;
    int carry = 0;
    
    while(i>=0 && j>=0) {
        int val1 = a[i];
        int val2 = b[j];
            
        int sum = val1 + val2 + carry;   
        
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    
    // first case
    while(i>=0) {
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    
     // second case
    while(j>=0) {
        int sum = b[j] + carry;
        carry = sum/10;
        int value = sum%10;
        ans.push_back(value);
        j--;
    }
    
     // second case
    while(carry != 0) {
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    
    //print(ans);
    return reverse(ans);
}
int main(){
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(0);
    v1.push_back(5);
    v1.push_back(4);
    v1.push_back(9);
    v1.push_back(5);
    vector<int> v2;
    v2.push_back(2);
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(5);
    v2.push_back(4);
    v2.push_back(9);
    v2.push_back(5);
    vector<int> sol=findArraySum(v1,7,v2,7);
    for(int i=0;i<sol.size();i++){
        cout<<sol[i]<<" ";
    }
}