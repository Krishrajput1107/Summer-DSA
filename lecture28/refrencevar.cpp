#include<iostream>
using namespace std;
void update2(int &n){
    n++;
    cout<<"Inside: "<<n<<endl;
}
void update(int n){
    n++;
    cout<<"Inside: "<<n<<endl;
}

int main(){
    /*
    int i=5;
    //create refrence variable
    int &j=i;
    cout<<i<<endl;
    cout<<j<<endl;
    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;
    */
   int n=5;
   cout<<"Before: "<<n<<endl;
   update2(n);
   cout<<"After: "<<n<<endl;

}