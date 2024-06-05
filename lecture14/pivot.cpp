#include<iostream>
using namespace std;
int pivotelement(int arr[],int size){
    int s=0,e=size-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int main(){
    int arr[7]={2,10,11,12,15,17,1};
    int ans=pivotelement(arr,7);
    cout<<"Index of Pivot element is: "<<ans<<endl;
}