#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    cout<<"size of vector: "<<v.size()<<endl;
    cout<<"capacity of vector: "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"size of vector: "<<v.size()<<endl;
    cout<<"capacity of vector: "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"size of vector: "<<v.size()<<endl;
    cout<<"capacity of vector: "<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"size of vector: "<<v.size()<<endl;
    cout<<"capacity of vector: "<<v.capacity()<<endl;
    v.resize(5);
    cout<<"size of vector: "<<v.size()<<endl;
    cout<<"capacity of vector: "<<v.capacity()<<endl;
    v.resize(7);
    cout<<"size of vector: "<<v.size()<<endl;
    cout<<"capacity of vector: "<<v.capacity()<<endl;
    v.resize(11);
    cout<<"size of vector: "<<v.size()<<endl;
    cout<<"capacity of vector: "<<v.capacity()<<endl;
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    cout<<"size of vector: "<<v.size()<<endl;
    cout<<"capacity of vector: "<<v.capacity()<<endl;
}
