#include<iostream>
using namespace std;

void reverse(char name[], int n){

    int start = 0;
    int end = n - 1;

    while(start<=end){
        swap(name[start], name[end]);
        start++;
        end--;
    }

}

void print(char name[], int n){

    for(int i=0; i<n; i++){
        cout<<name[i]<<" ";
    }
    
    cout<<endl;
}



int main() {

    char name[8] = {'P','r','a','k','r','i','t','i'};

    reverse(name, 8);

    cout<<name;

    return 0;

}