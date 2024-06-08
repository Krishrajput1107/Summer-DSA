#include<iostream>
#include<vector>
using namespace std;
vector<int> bubbleSort(vector<int>arr)
{   
    // Write your code here.
    for(int i=1;i<arr.size();i++){
        bool swapped=false;
        for(int j=0;j<arr.size()-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
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
    vector<int> ans=bubbleSort(arr);
    cout<<"Sorted array is: "<<endl;
    printArray(ans);
}
