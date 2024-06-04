#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int sort0and1(int arr[],int size){
    int first=0;
    int last=size-1;
    while(first<last){
        while(arr[first]==0 && first<last){
            first++;
        }
        while(arr[last]==1 && first<last){
            last--;
        }
        if(first<last){
            swap(arr[first],arr[last]);
            first++;
            last--;
        }
        printArray(arr, size );

    }

}
int main(){
    int size;
    cout<<"enter the size of the array: "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    sort0and1(arr,size);
}