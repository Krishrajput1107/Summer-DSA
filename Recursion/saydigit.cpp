#include<iostream>
using namespace std;
void sayDigit(int n, string arr[]){
    //base case
    if(n==0){
        return;
    }
    //processing
    int digit=n%10;
    n=n/10;
    //cout<<arr[digit]<<" ";
    //recursive function
    sayDigit(n,arr);
    cout<<arr[digit]<<" ";
}
int main(){
    int n;
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    cout<<"Enter number: "<<endl;
    cin>>n;
    sayDigit(n,arr);   

}

