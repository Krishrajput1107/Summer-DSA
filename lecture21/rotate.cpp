#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int> arr, int r){
    for(int j=r+1;j<arr.size();j++){
        cout<<arr[j]<<" ";
        }
    for(int i=0;i<=r;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> v;
    int r;
    cout<<"Enter r:"<<endl;
    cin>>r;
    v.push_back(2);
    v.push_back(13);
    v.push_back(0);
    v.push_back(5);
    v.push_back(4);
    v.push_back(19);
    v.push_back(5);
    rotate(v,r);
}