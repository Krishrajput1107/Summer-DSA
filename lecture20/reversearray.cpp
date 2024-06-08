#include<iostream>
#include<vector>
using namespace std;
vector<int> reverse(vector<int> v,int m){
    int s=m+1;
    int e=v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}
void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    int m;
    cout<<"Enter the value of m: "<<endl;
    cin>>m;
    vector<int> v;
    v.push_back(11);
    v.push_back(13);
    v.push_back(5);
    v.push_back(8);
    v.push_back(2);
    v.push_back(19);
    v.push_back(21);
    vector<int> ans=reverse(v,m);
    cout<<"Printing reverse array: "<<endl;
    printVector(ans);

}