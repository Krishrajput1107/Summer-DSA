#include<iostream>
using namespace std;
long long int SqrtInteger(int n){
        long long int ans=0;
        int s=0;
        int e=n;
        long long int mid=s+(e-s)/2;
        while(s<=e){
            long long int square=mid*mid;
            if(square==n){
                return mid;
            }
            if(square < n){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        mid=s+(e-s)/2;
        }
    return ans;
}
double morePrecision(int n,int precision, int tempSol){
    double factor=1;
    double ans=tempSol;
    for(int i=0;i<precision;i++){
        factor=factor*0.1;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;

}
int main(){
    int n;
    cout<<"Enter any number "<<endl;
    cin>>n;
    int tempSol=SqrtInteger(n);
    cout<<"Answer is: "<<morePrecision(n,3,tempSol);
}