#include<iostream>
using namespace std;
int partition(int arr[],int s,int e){
    int cnt=0;
    int pivot=arr[s];
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            cnt++;
        }
    }
    int i=s;
    int j=e;
    int pivotIndex=s+cnt;
    swap(arr[s],arr[pivotIndex]);
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;

}
void quickSort(int arr[],int s,int e){
    //base case
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);
    //left part
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
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
    int s=0;
    int e=size-1;
    quickSort(arr,s,e);  
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    } 
    cout<<endl;
}