#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v(5);
    for(int i=0;i<5;i++){
        cin>>v[i];
    }
    int x,occurence=0;
    cout<<"Enter x: "<<endl;
    cin>>x;
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            occurence=i;
        }
    }
    cout<<"Last occurence is: "<< occurence;

}