#include<iostream>
#include<vector>
using namespace std;
vector<int> movezeroes(vector<int> arr){
    int i=arr.size();
    for(int j=arr.size();j>0;j--){
        if(arr[j]!=0){
            swap(arr[i],arr[j]);
            i--;
        }
    }
    return arr;
}
void printVector(vector<int> ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int> v;
    v.push_back(0);
    v.push_back(13);
    v.push_back(0);
    v.push_back(0);
    v.push_back(2);
    v.push_back(19);
    v.push_back(0);
    vector<int> ans=movezeroes(v);
    cout<<"Printing reverse array: "<<endl;
    printVector(ans);
}