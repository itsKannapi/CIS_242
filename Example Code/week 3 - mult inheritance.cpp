#include<iostream>
#include <sstream>
using namespace std;

class A { 
   int a;
   public :
   A() { 
      cout<<"A is fired "<<endl;
      a=0;
   }
   int getA(){ return a;}
   // print Employee object
   string toString() const {
      ostringstream output;
      output << "A value is " << a <<endl;
      return output.str();
   }
};
class B{

   int a;
   public :
   B() { 
      cout<<"B is fired "<<endl;
      a=1;
   }
   int getB(){ return a;}
};
class C: public A, B{ //note the order
   int a;
   public:
      C() { cout<< "C is fired " <<endl;
      a=2;
      }
   int getA(){ return a;}
   string toString() const {
      ostringstream output;
      output << "C value is " << a <<endl;
      return output.str();
   }
};

int main(){

C c;
A a;
B b;

//BEWARE OF RELATIONSHIP AND WHAT WE CAN INHERIT?
//AVOID CONFLICTING FUNCTIONS
//cout<<a.getA()<<" "<<b.getB()<<" "<<c.getA()<<endl;
//cout<<c.getA()<<" "<<c.getB()<<endl;
cout<<"Object output: "<<a.toString()<<endl;
cout<<"Object output: "<<c.toString()<<endl;
}