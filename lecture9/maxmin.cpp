#include<iostream>
using namespace std;
int main(){
    int arr[10]={20,43,53,12,1193,23,43,48,907,17};
    int max=INT16_MIN,min=INT16_MAX;
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        if(max<arr[i]){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }
    cout<<"Maximum Value "<<max<<endl;
    cout<<"Minimum Value "<<min<<endl; 
}