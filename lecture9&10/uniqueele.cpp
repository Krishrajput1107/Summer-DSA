#include<iostream>
using namespace std;
int main(){
    int size,ans=0;
    cout<<"Enter any odd number in size"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The unique element in the array is "<<endl;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
        }
        cout<<ans<<endl;
}