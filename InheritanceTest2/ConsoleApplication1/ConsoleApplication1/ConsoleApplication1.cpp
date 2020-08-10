// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "virtual_member_access.h"


int main()
{
	A* a = new A();
	a->access();

	B* b = new B();
	b->access();

	C* c = new C();
	c->access();

	D* d = new D();
	d->access();

	E* e = new E();
	e->access();

	F* f = new F();
	f->access();

	G* g = new G();
	g->access();

	H* h = new H();
	h->access();
	std::cout << "members accessed" << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
