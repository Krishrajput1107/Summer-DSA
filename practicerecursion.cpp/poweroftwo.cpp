#include<iostream>
using namespace std;
int poweroftwo(int n){
    if(n==0){
        return 1;
    }
    int smallerproblem=poweroftwo(n-1);
    int biggerproblem=2*smallerproblem;
    return biggerproblem;
}
int main(){
    int n;
    cout<<"Enter any number: "<<endl;
    cin>>n;
    int ans=poweroftwo(n);
    cout<<"2 power "<<n<<" is "<<ans<<endl;
}