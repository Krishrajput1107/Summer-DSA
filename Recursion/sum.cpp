#include<iostream>
using namespace std;
int Sum(int *arr,int size){
    int sum=0;
    if(size==0 ){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int remainingpart=Sum(arr+1,size-1);
    sum=arr[0]+remainingpart;
    return sum;
}
int main(){
    int size;
    cout<<"Size of array: "<<endl;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }   
    int ans=Sum(arr,size);
    cout<<ans;
}