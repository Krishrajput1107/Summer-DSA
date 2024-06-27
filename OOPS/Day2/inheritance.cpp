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
    int setAge(int weight){
        this->weight=weight;
    }
};
class Male : public Human{
    public:
    string colour;
    void sleep(){
        cout<<"Male sleeping "<<endl;
    }
};
int main(){
    Male obj1;
    cout<< obj1.age<< endl;
    cout<< obj1.height<< endl;
    cout<< obj1.weight<< endl;
    cout<< obj1.colour<< endl;
}