#include<iostream>
#include<vector>
using namespace std;
int pivotelement(vector<int> arr,int size){
    int s=0,e=size-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}
int binarySearch(vector<int> arr,int s, int e,int key){

    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        else if(key>arr[mid]){
            s=mid+1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int search(vector<int> arr, int n, int k)
{
    int ans;
    int pivot=pivotelement(arr,n);
    if(k>=arr[pivot] && k<=arr[n-1]){
        ans=binarySearch(arr,pivot,n-1,k);
    }
    else{
        ans=binarySearch(arr,0,pivot-1,k);
    }
    return ans;
    // Write your code here.
    // Return the position of K in ARR else return -1.
    //done
}
int main(){
    int size;
    cout<<"Enter teh size of the array: "<<endl;
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter elements in array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter element to be searched"<<endl;
    cin>>k;
    int ans=search(arr,size,k);
    cout<<"Index of peak element is: "<<ans;
}
