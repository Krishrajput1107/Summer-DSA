#include<iostream>
using namespace std;
int Sum(int arr[],int size){
    int sum=0;
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
   sum=arr[0]+(Sum(arr+1,size-1));
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
    int ans=Sum(arr,size);
    cout<<ans<<endl;
}
