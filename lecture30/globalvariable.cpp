#include<iostream>
using namespace std;

int score=15;
void a(int& i){
    cout<<i<<endl;
    cout<<"in a "<<score<<endl;
    score++;
    //b(i);
}
void b(int& i){
    cout<<i<<endl;
    cout<<"in b "<<score<<endl;

}
int main(){
    int i=5;
    a(i);
    b(i);
    cout<<"in main "<<score<<endl;
}