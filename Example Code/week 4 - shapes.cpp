#include<iostream>

using namespace std;

class Shape {  // base class

protected:
	double height, width;
	char name[20];
public:
	Shape() {  // general case
		width = height = 0;
		strcpy_s(name, "unknown");
	}
	char* getName() { return name; }
	virtual double area() {
		cout << " Error: area() must be overridden\n";
		return 0;
	}
};
class Triangle : public Shape{

public:
	Triangle() {
		strcpy_s(name, "Triangle");
	}
	double area(int h, int w) { return w * h / 2; }
	double area( ) { return 5 * 4  / 2; }   // APPLYING OVERRIDE
};
class Rectangle : public Shape {

public:
	Rectangle() {
		strcpy_s(name, "Rectangle");
	}
	double area(int h, int w) { return w* h; }
	double area() { return 5 * 4; }        // APPLYING OVERRIDE
};

int main() {

	Shape* shapes[5];  // base class ptr (array of shapes)

	// compose array references

	shapes[0] = new Triangle();
	shapes[1] = new Rectangle();
	shapes[2] = new Shape();
	shapes[3] = new Triangle();
    shapes[4] = new Rectangle();



	for (int i = 0; i < 5; ++i) {

		cout << " Area so far for " << shapes[i]->getName() << " is " << shapes[i]->area();

	}

	// set & call child area function

	Triangle tri;

	cout << "\n" << tri.area(5, 5) << endl;



}