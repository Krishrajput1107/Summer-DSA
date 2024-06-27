#include<iostream>
using namespace std;
class Human{
    public:
    int height;
    int weight;
    int age;
    public:
    int getAge(){
        return this->age;
    }
    void setweight(int weight){
        this->weight=weight;
    }
};
class Male : protected Human{
    public:
    string colour;
    void sleep(){
        cout<<"Male sleeping "<<endl;
    }
    int getHeight(){
        return this->height;
    }
};
int main(){
    Male m1;
    cout<<m1.getHeight()<<endl;







    /*
    Male obj1;
    cout<< obj1.age<< endl;
    cout<< obj1.height<< endl;
    cout<< obj1.weight<< endl;
    cout<< obj1.colour<< endl;
    obj1.sleep();
    obj1.setweight(80);
    cout<< obj1.weight<< endl;
    */
}