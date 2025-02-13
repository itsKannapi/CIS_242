#pragma once
#include<iostream>
using namespace std;
class Student {
    private:
        string name;
    public:
        Student(string n) {
            this->name = n;
        }
        void setName(string n) { 
            name = n; 
        }
        string getName(){ 
            return name; 
        }
};