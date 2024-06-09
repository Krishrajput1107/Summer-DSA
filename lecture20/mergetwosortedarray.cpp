#include<iostream>
using namespace std;
void mergearray(int arr1[],int n, int arr2[], int m,int arr3[]){
    int i=0,j=0;
    int k=0;
    while((i<n) && (j<m)){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
            
        }
        else{
            arr3[k++]=arr2[j++];
          
        }
    }
    while(i<n){
        arr3[k++]=arr1[i++];
        
    }
    while(j<m){
        arr3[k++]=arr2[j++];
        
    }
}
void printarray(int arr3[],int size){
    for(int i=0;i<size;i++){
        cout<<arr3[i]<<" ";
    }
}
int main(){
    int arr1[6]={1,4,6,8,9,10};
    int arr2[4]={2,3,5,7};
    int arr3[10]={0};
    mergearray(arr1,6,arr2,4,arr3);
    printarray(arr3,10);
}