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
    a.sethealth(80);
    a.setlevel('A');
    cout<<"Level is:"<<a.level<<endl;
    cout<<"Health is:"<<a.gethealth()<<endl;

    //Dynamic allocation
    Hero *b = new Hero;
    b->sethealth(50);
    b->setlevel('Z');

    cout<<"Level is:"<<(*b).level<<endl;
    cout<<"Health is:"<<(*b).gethealth()<<endl;

    //alternate way to write
    cout<<"Level is:"<<b->level<<endl;
    cout<<"Health is:"<<b->gethealth()<<endl;


}