#include<iostream>
#include<vector>
using namespace std;
void SelectionSort(vector<int> arr, int size){
    for(int i=0;i<size-1;i++){
        int minIndex=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}
void printArray(vector<int> arr,int size){
    cout<<"Sorted array is: "<<endl;
    for(int t=0;t<size;t++){
        cout<<arr[t];
    }
}
int main(){
    vector<int> arr;
    int size;
    cout<<"Enter the size of vector "<<endl;
    cin>>size;
    cout<<"Enter elements in the vector: "<<endl;
    for(int k=0;k<size;k++){
        cin>>arr[k];
    }
   SelectionSort(arr,size);
   printArray(arr,size);
}