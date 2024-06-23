#include<iostream>
using namespace std;
int Sumofele(int arr[],int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int remainingpart=Sumofele(arr+1,size-1);
    int sum=arr[0]+remainingpart;
    return sum;
}
int main(){
    int size;
    cout<<"Enter size: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int ans=Sumofele(arr,size);
    cout<<ans;   
}