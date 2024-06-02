#include<iostream>
using namespace std;

int swaparray(int arr[] , int size){
    int s=0;
    int e=size-1;
    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}
int printarray(int arr[] , int size){
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
    cout<<endl;
}

int main(){
    int evenarr[]={2,4,6,1,5,9};
    int oddarr[]={1,2,3,4,5};
    swaparray(evenarr,6);
    swaparray(oddarr,5);
    printarray(evenarr,6);
    printarray(oddarr,5);

}