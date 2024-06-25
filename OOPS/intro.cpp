#include<iostream>
using namespace std;
class Hero{
    //properties;
    private:
    int health=50;
    public:
    char level;
    void print(){
        cout<<level;
    }
    int gethealth(){
        return health;
    }
    char getlevel(){
        return level;
    }
    void sethealth(int h){
        health=h;
    }
    void setlevel(char l){
        level=l;
    }

};
int main(){
    //creation of object
    Hero baaki;
    cout<<"Health is: "<<baaki.gethealth()<<endl;
    baaki.sethealth(20);
    cout<<"Health is: "<<baaki.gethealth()<<endl;
    //cout<<"Health is: "<<baaki.sethealth(5)<<endl;
    //baaki.health=60;
    baaki.level='A';
    cout<<"Size: "<<sizeof(baaki)<<endl;
    //cout<<"Health: "<<baaki.health<<endl;
    cout<<"level: "<<baaki.level<<endl;
}