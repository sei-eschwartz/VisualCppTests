// This file was mostly taken from the following repository.
// https://github.com/astrelsky/InheritanceTests

#include "virtual_member_access.h"
#include <iostream>

/*
	These are for determining how to appropriatly decompile the accessing of
	members.
*/


int AbstractA::access() {
	std::cout << "AbstractA access";
	abstract_a_data = 1;
	return abstract_a_data;
}

int A::access() {
	std::cout << "A access";
	a_data = 1;
	return a_data;
}

int B::access() {
	std::cout << "B access";
	a_data = 1;
	b_data = 2;
	a_data = A::access();
	return b_data;
}

int C::access() {
	std::cout << "C access";
	a_data = 1;
	c_data = 2;
	a_data = A::access();
	return c_data;
}

int D::access() {
	std::cout << "D access";
	a_data = 1;
	b_data = 2;
	c_data = 3;
	d_data = 4;
	a_data = A::access();
	b_data = B::access();
	c_data = C::access();
	return d_data;
}

void E::abstract_a_foo() {
	std::cout << "E abstract_a_foo";
}

int E::access() {
	std::cout << "E access";
	abstract_a_data = 1;
	e_data = 2;
	abstract_a_data = AbstractA::access();
	return e_data;
}

void F::abstract_a_foo() {
	std::cout << "F abstract_a_foo";
}

int F::access() {
	std::cout << "F access";
	abstract_a_data = 1;
	f_data = 2;
	abstract_a_data = AbstractA::access();
	return f_data;
}

int G::access() {
	std::cout << "G access";
	E::abstract_a_data = 1;
	F::abstract_a_data = 1;
	e_data = 2;
	f_data = 3;
	g_data = 4;
	e_data = E::access();
	f_data = F::access();
	return g_data;
}

int H::access() {
	std::cout << "H access";
	E::abstract_a_data = 1;
	F::abstract_a_data = 1;
	e_data = 2;
	f_data = 3;
	h_data = 4;
	e_data = E::access();
	f_data = F::access();
	return h_data;
}