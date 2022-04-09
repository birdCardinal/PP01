#include <iostream>
using namespace std;

class A {
public:
	virtual void dynamic_print() {
		cout << "´ÙÀÌ³ª¹ÌÅ© µ¥Çò\n";
	}
	void static_print() {
		cout << "µ¥Çò\n";
	}
	void static_print(int a) {
		cout << a << "ÇìÂm\n";
	}
};
class B :public A{
public:
    void dynamic_print() {
		cout << "´ÙÀÌ³ª¹ÌÅ© ÇìÂm\n";
	}
	void static_print() {
		cout << "ÇìÂm\n";
	}
};

void main() {
	A* temp;
	B* temp2 = new B();
	temp = temp2;
	temp->dynamic_print();
	temp2->dynamic_print();
}