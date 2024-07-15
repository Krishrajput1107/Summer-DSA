#include<iostream>
#include<queue>
using namespace std;

struct petrolpump{
    int petrol;
    int distance;
};

class Sol{
    public:
    int tour(petrolpump p[],int n){
        int deficit=0;
        int balance=0;
        int start=0;
        for(int i=0;i<n;i++){
            balance+=p[i].petrol-p[i].distance;

            if(balance<0){
                start=i+1;
                deficit+=balance;
                balance=0;
            }
        }
        if(balance+deficit>=0){
            return start;
        }
        else{
            return -1;
        }
    }


};
int main(){
    int n;
    cout<<"Enter number of petrol pump: "<<endl;
    cin>>n;
    petrolpump p[n];
    int petrol;
    int distance;
    for(int i=0;i<n;i++){
        cin>>p[i].petrol>> p[i].distance;
    }

    Sol obj;
    cout<< obj.tour(p,n) <<endl;



} 