// Constructor 

#include<iostream>
using namespace std;

class Hero{

    // properties
    private:
    int health;
    public:
    char *name;
    char level;

    //default constructor 
    Hero(){
        cout<<"this->"<<this<<endl;
        cout<<"Constructor called "<<endl;
        name = new char[100];
    }

    //parameterized constuctor 
    Hero(int health){
        this->health = health; // using this keyword 
    }
    Hero(int health, char ch){
        this->level = ch;
        this->health = health; 
        
    }

    //copy constructor 
    Hero(Hero& temp){
        cout<<"Copy constructor called "<<endl;
        this->health = temp.health;
        this->level = temp.level;
        
        
    }

    void print(){
        cout<<endl;
        cout<<"[ Name is: "<<this->name<<" '";
        cout<<"health is"<< this->health <<" '";
        cout<<"level is "<< this->level <<" ]";
        cout<<endl;
    }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        this->health = h;
    }

    void setLevel(char ch){
        this->level = ch;
    }

    void setName(char name[]){
        this->name = name;
    }

};

int main() {

 /*   Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

    hero1.print();



    Hero S(70, 'C');
    S.print();

    // copy constructor 
    Hero R(S);
    R.print();

*/


    // object creation statically 
    Hero ramesh(10);
    //cout<<"Address of ramesh is "<<&ramesh<<endl;

    // dynamically 
    Hero *h = new Hero;
    //or
    Hero *b = new Hero();
    h->print();

    Hero temp(22,'B');
    temp.print();

    return 0;
    
}