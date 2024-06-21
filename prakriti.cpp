#include<iostream>
using namespace std;

int findDuplicate(int arr[], int size){

    int ans = 0;
    for(int i=0; i<size-1; i++){
        ans = ans ^ arr[i];
    }

    for(int i=0; i<size; i++){
        ans = ans^arr[i];
    }

    return ans;
}

int main() {

    int arr[5] = {1,2,7,8,2};

    int array = findDuplicate(arr,5);

    cout<<array<<endl;

    return 0;

}