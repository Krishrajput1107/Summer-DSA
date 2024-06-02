#include<iostream>
using namespace std;
int main(){
    int hn,fn,twn,ten,one;
    int amount;
    cout<<"Enter the amount"<<endl;
    cin>>amount;
    hn=amount/100;
    amount=amount%100;
    fn=amount/50;
    amount=amount%50;
    twn=amount/20;
    amount=amount%20;
    ten=amount/10;
    amount=amount%10;
    one=amount/1;
    cout<<"Number of 100 notes "<<hn<<endl;
    cout<<"Number of 50 notes "<<fn<<endl;
    cout<<"Number of 20 notes "<<twn<<endl;
    cout<<"Number of 10 notes "<<ten<<endl;
    cout<<"Number of 1 notes "<<one<<endl;
}