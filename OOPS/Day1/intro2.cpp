#include<iostream>
using namespace std;
class Hero{
    private:
    int health;
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
    void setlevel(char ch){
        level=ch;
    }

};
int main(){
    //static allocation
    Hero a;

    //Dynamic allocation
    Hero *b = new Hero;

}