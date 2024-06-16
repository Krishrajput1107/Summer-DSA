#include<iostream>
using namespace std;
int getSum(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    return sum;
}

int main(){
    char ch='a';
    cout<<"size of character: "<<sizeof(ch)<<endl; 
    char *p=&ch;
    cout<<"size of pointer: "<<sizeof(p)<<endl;
    int n;
    cout<<"Enter size: "<<endl;
    cin>>n;
    //variable size array
    int *arr = new int[n];
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=getSum(arr,n);
    cout<<"Sum is: "<<ans<<endl;

}