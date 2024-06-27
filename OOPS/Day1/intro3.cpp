#include<iostream>
using namespace std;
class Hero{
    private:
    int health;
    public:
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
    char level='Z';
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

};
int main(){
//cout<<"Hi"<<endl;
    //object created statically
   Hero ramesh(10);
   ramesh.print();
   cout<<"Address of ramesh is: "<<&ramesh<<endl;
//cout<<"Hello"<<endl;
    //Dyanmically
    Hero *h=new Hero();
    h->print();

    Hero temp(22,'B');
    temp.print();
}