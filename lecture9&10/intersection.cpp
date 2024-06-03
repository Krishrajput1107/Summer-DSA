#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> ans; 
    int arr1[7]={1,2,3,2,4,5,6};
    int arr2[9]={3,2,7,6,1,90,3,13,32};
    for(int i=0;i<7;i++){
        int element=arr1[i];
        for(int j=0;j<9;j++){
            if(element==arr2[j]){
                ans.push_back(element);
                arr2[j]=INT16_MIN;
                break;
            }
        }
    }
    for (auto elem : ans) {
        cout << elem << endl;
    }

}