#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int> &arr, int x)
{
	// Write your code here.
	int firstocc,lastocc;
    vector<int> sol;
	for(int i=0;i<arr.size();i++){
		if(arr[i]==x){
			firstocc=i;
            sol.push_back(firstocc);
			break;
		}
	}
	for(int i=0;i<arr.size();i++){
		if(arr[i]==x){
			lastocc=i;
		}
	}
	sol.push_back(lastocc);
    return sol;
}
int main(){
    vector<int> arr={1,2,3,4,2,6,3};
    int x;
    cout<<"Enter the value of x: "<<endl;
    cin>>x;
    vector<int> ans=searchRange(arr,x);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}