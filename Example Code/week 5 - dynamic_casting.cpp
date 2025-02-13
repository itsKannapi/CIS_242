#include<iostream>
#include<typeinfo> // for typeid checker

using namespace std;
class b {
public:
	b() { cout << "Constructing base\n"; }
	virtual void foo() { cout << "Foo executed from base"; }
};
class d : public b {
public:
	d() { cout << "Constructing derived\n"; }
	void foo() { cout << "Foo executed from derived"; }
};

int main() {
	int i, j;
	char c;

	b bobj;
	d dobj;

	b* bptr = new d();
	d* derived = (d*)bptr;  // dynamic casting

	// get the type info using typeid operator

	const type_info& ti1 = typeid(i);
	const type_info& ti2 = typeid(j);
	const type_info& ti3 = typeid(c);

	const type_info& ti4 = typeid(*bptr);
	const type_info& ti5 = typeid(*derived);

	cout << "ti1 => " << ti1.name();
	cout << "\nti2 => " << ti2.name();
	cout << "\nti3 => " << ti3.name();
	cout << "\nti4 => " << ti4.name();
	cout << "\nti5 => " << ti5.name();

	if (ti4 == ti5) 
		cout << "\nSimilar types\n";
	else
		cout << "\nDissimilar types\n";

	derived->b::foo();  // the power of polymorphism

	return 0;
}