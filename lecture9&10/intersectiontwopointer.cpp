#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr1[7]={1,2,2,3,4,5,6};
    int arr2[9]={2,3,3,5,6,9,10,11,12};
    int i=0,j=0;
    vector<int> ans;
    while(i<7 && j<9){
        if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]>arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    for (auto elem : ans) {
        cout<< elem << endl;
    }

}