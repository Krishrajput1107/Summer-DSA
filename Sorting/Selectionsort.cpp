#include<iostream>
#include<vector>
using namespace std;
vector<int> SelectionSort(vector<int> arr){
    for(int i=0;i<arr.size()-1;i++){
        int minIndex=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
    return arr;
}
void printArray(vector<int> arr){
    cout<<"Sorted array is: "<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(11);
    arr.push_back(8);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(17);
    arr.push_back(19);
   vector<int> ans=SelectionSort(arr);
   printArray(ans);
}