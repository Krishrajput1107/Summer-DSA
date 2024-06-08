#include<iostream>
#include<vector>
using namespace std;
void insertionSort(int n, vector<int> &arr){
    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { // ruk jao
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp; 
    }
}
int main(){
    vector<int> arr;
    int size;
    cout<<"Enter the size of vector "<<endl;
    cin>>size;
    cout<<"Enter elements in the vector: "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"ANSWER"<<endl;
    insertionSort(size,arr);
    cout<<"Sorted array is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
    cout<<"done"<<endl;
   
}