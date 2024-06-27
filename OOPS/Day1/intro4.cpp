#include<iostream>
using namespace std;
class Hero{
    private:
    int health;
    public:
    char level;

    //simple constructor
    Hero(){
        cout<<"Mae default constructor hu"<<endl;
    }


    //parameterized constructor
    Hero(int health){
        this->health=health;
        cout<<"this->"<<this<<endl;
    }
    Hero(int health,char level){
        this->health=health;
        this->level=level;
        //cout<<"this is ad ->"<<this<<endl;
    }


    //copy constructor
    Hero(Hero&temp){
        cout<<"Copy constructor called"<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }


    void print(){
        cout<<"level: "<<this->level<<endl;
        cout<<"health: "<<this->health<<endl;
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
    Hero suresh(70,'C');
    suresh.print();
    Hero R(suresh);
    R.print();
   // cout<<suresh.gethealth()<<endl;
    //cout<<suresh.level<<endl;
}