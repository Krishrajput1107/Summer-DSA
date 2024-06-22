#include<iostream>
using namespace std;
void merge(int arr[], int s , int e){
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *arr1= new int[len1];
    int *arr2=new int[len2];

    //copying elements in array 1
    int mainIndex=s;
    for(int i=0;i<len1;i++){
        arr1[i]=arr[mainIndex++];
    }
    //copying elements in array 2
    mainIndex=mid+1;
    for(int i=0;i<len2;i++){
        arr2[i]=arr[mainIndex++];
    }

    //merging both array
    int index1=0;
    int index2=0;
    mainIndex=s;
    while((index1<len1)&&(index2<len2)){
        if(arr1[index1]<arr2[index2]){
            arr[mainIndex++]=arr1[index1++];
        }
        else{
            arr[mainIndex++]=arr2[index2++];
        }
    }
    while(index1<len1){
        arr[mainIndex++]=arr1[index1++];
    }
    while(index2<len2){
        arr[mainIndex++]=arr2[index2++];
    }
    delete []arr1;
    delete []arr2;
}
    

void mergeSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    //left wala part
    mergeSort(arr,s,mid);

    //right wala part
    mergeSort(arr,mid+1,e);

    //merge two sorted array
    merge(arr,s,e);
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
    mergeSort(arr,s,e);   
    for(int i=0;i<e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}