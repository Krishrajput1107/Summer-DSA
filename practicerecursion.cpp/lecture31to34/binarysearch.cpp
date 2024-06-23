#include<iostream>
using namespace std;


bool binarySearch(int arr[], int s,int e, int k ) {
    int mid=s+(e-s)/2;
    //base case
    if(s>e) 
        return false;

    if(arr[mid] == k) {
        return true;
    }
    if(k>arr[mid]){
        bool remp=binarySearch(arr,mid+1,e,k);
        return remp;
    }
    else{
        bool remp=binarySearch(arr,s,mid-1,k);
        return remp;
    }
    mid=s+(e-s)/2;
}

int main() {

    int arr[5] = {3,5,6,8,11};
    int s=0;
    int size = 5;
    int e=size-1;
    int key;
    cout<<"Enter key: "<<endl;
    cin>>key;
    bool ans = binarySearch(arr, s,e, key);

    if(ans ){
        cout << "Present " << endl;
    }
    else{
        cout << " Not present " << endl;
    }

    return 0;
}