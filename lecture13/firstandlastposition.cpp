#include<iostream>
using namespace std;
vector<int> searchRange(vector<int> &arr, int x)
{
	// Write your code here.
	int firstocc=0,lastocc=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]==x){
			firstocc=i;
			break;
		}
	}
	arr.push_back(firstocc);
	for(int i=0;i<arr.size();i++){
		if(arr[i]==x){
			lastocc=i;
		}
	}
	arr.push_back(lastocc);
}
int main(){

}