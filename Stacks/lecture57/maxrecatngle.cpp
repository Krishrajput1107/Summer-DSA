#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(int *arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;

}

vector<int> prevSmallerElement(int *arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1 && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;

}

int largestRectangle(int *heights,int n){
    vector<int> next(n);
    next=nextSmallerElement(heights,n);

    vector<int> prev(n);
    prev=prevSmallerElement(heights,n);

    int area=INT16_MIN;
    for(int i=0;i<n;i++){
        int l=heights[i];

        if(next[i]==-1){
            next[i]=n;
        }
        int b=next[i]-prev[i]-1;
        int newArea=l*b;

        area=max(area,newArea);

    }
    return area;
}

int maxArea(int arr[][4],int m, int n){
    //computer area for first row
    int area=largestRectangle(arr[0],m);

    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                //row update adding previous row elements
                arr[i][j]=arr[i][j]+arr[i-1][j];
            }
            else{
                arr[i][j]=0;
            }
        }

            //entire row is updated now
            area=max(area,largestRectangle(arr[i],m));
    }
    return area;
}


int main(){

    int arr[4][4];
    cout<<"Enter row and col: "<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    int ans=maxArea(arr,4,4);
    cout<<"Area of largest rectangle is: "<<ans<<endl;
}