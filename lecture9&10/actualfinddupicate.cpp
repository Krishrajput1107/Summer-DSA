#include<iostream>
using namespace std;
int main(){
    int arr[7]={1,2,5,4,3,6,2};
    int ans=0;
    for(int i=0;i<7;i++){
        ans=ans^arr[i];
    }
    for(int i=1;i<7;i++){
        ans=ans^i;

    }
    cout<<ans;
}