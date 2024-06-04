#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    vector<int> arr;
    vector<vector<int>> ans;
    int s;
    cout<<"Enter the vealue of s: "<<endl;
    cin>>s;
    cout<<"Enter elements in the vector "<<endl;
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }   
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==s){
                vector<int> temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                ans.push_back(temp);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++){
            cout<<ans[i];
        } 
    }
}