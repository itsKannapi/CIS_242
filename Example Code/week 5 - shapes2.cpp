#include<iostream>

using namespace std;

class Shape {  // abstract base class

protected:
	double height, width;
	char name[20];
public:
	Shape() {  // general case
		width = height = 0;
		strcpy(name, "unknown");
	}
	char* getName() { return name; }
	virtual double area() = 0; // pure virtual function


};
class Triangle : public Shape {

public:
	Triangle() {
		strcpy(name, "Triangle");
	}
	double area(int h, int w) { return w * h / 2; }
	double area() { return width * height / 2; }   // APPLYING OVERRIDE
};
class Rectangle : public Shape {

public:
	Rectangle() {
		strcpy(name, "Rectangle");
	}
	double area(int h, int w) { return w * h; }
	double area() { return 5 * 4; }        // APPLYING OVERRIDE
};

int main() {

	Shape* shapes[5];  // base class ptr (array of shapes)
	//Shape myshape; -> not allowed!!!
	// compose array references

	shapes[0] = new Triangle();
	shapes[1] = new Rectangle();
	shapes[2] = new Rectangle();
	shapes[3] = new Triangle();
	shapes[4] = new Rectangle();

	for (int i = 0; i < 5; ++i) {
		//string name = shapes[i]->getName();
		int area = shapes[i]->area();
		cout<< ((strcmp(shapes[i]->getName(),"Rectangle") == 0) ? to_string(area) + " " : "") ;

	}





}
