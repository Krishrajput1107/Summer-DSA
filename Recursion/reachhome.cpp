#include<iostream>
using namespace std;
void reachhome(int src, int dest){
    cout<<"Source "<<src<<" destination "<<dest<<endl;
    if(src==dest){
        cout<<"phoch gya! "<<endl;
        return;
    }
    src++;
    reachhome(src,dest);
}

int main(){
    int src=1;
    int dest=10;
    reachhome(src,dest);   
}