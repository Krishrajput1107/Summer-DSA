#include<iostream>
using namespace std;
class Hero{
    //properties;
    private:
    int health=50;
    public:
    char level='d';
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
    //static allocation
    Hero a;
    char level='B';
    cout<<a.health;
}