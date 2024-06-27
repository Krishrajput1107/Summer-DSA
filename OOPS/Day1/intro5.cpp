#include<iostream>
using namespace std;
class Hero{
    private:
    int health;
    public:
    char level;
    char *name;

    //simple constructor
    Hero(){
        cout<<"Mae default constructor hu"<<endl;
        name=new char[100];
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
   // Hero(Hero&temp){
      //  this->health=temp.health;
       // this->level=temp.level;
    //}


    void print(){
        cout<<endl;
        cout<<"[ ";
        cout<<"level: "<<this->level<<" ";
        cout<<"health: "<<this->health<<" ";
        cout<<"name: "<<this->name;
        cout<<" ]";
        cout<<endl;
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
    void setName(char name[]){
        this->name=name;
    }

};
int main(){
    Hero hero1;
    hero1.sethealth(80);
    hero1.setlevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);
    hero1.print();

    //default copy constructor
    Hero hero2(hero1);
    hero2.print();  
    hero1.name[0]='D'; 
    hero1.print();  
    hero2.print();
}