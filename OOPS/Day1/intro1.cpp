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
    Hero h1;
    cout<<"Size of h1 is: "<<sizeof(h1)<<endl;
    //h1.health=70;
    h1.level='A';
    //cout<<"Health is: "<<h1.health<<endl;
    cout<<"Level is: "<<h1.level<<endl;
    //use setter
    h1.sethealth(50);
    //use getter
    cout<<h1.gethealth()<<" "<<endl;
    h1.setlevel('B');
    cout<<h1.getlevel()<<endl;


}