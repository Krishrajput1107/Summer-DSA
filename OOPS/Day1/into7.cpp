#include<iostream>
using namespace std;
class Hero{
    private:
    int health;
    public:
    char level='Z';
    static int timetoComplete;
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
        cout<<"this is ad ->"<<this<<endl;
    }
    void print(){
        cout<<level<<endl;
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
    ~Hero(){
        cout<<"Distructor called "<<endl;
    }
};

int Hero::timetoComplete=5;

int main(){
    cout<< Hero::timetoComplete <<endl;

}