#include <iostream>
using namespace std;

class A {
public:
	virtual void dynamic_print() {
		cout << "���̳���ũ ����\n";
	}
	void static_print() {
		cout << "����\n";
	}
	void static_print(int a) {
		cout << a << "���m\n";
	}
};
class B :public A{
public:
    void dynamic_print() {
		cout << "���̳���ũ ���m\n";
	}
	void static_print() {
		cout << "���m\n";
	}
};

void main() {
	A* temp;
	B* temp2 = new B();
	temp = temp2;
	temp->dynamic_print();
	temp2->dynamic_print();
}