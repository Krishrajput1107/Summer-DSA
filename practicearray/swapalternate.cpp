#include<iostream>
using namespace std;
int main(){
    int arr[8]={1,2,3,4,5,6,7,8};
    int s=0;
    int e=s+1;
    while(e<8){
        swap(arr[s],arr[e]);
        s=s+2;
        e=e+2;
    }
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}