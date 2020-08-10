// This file was mostly taken from the following repository.
// https://github.com/astrelsky/InheritanceTests

#include <iostream>

#ifndef VIRTUAL_MEMBER_ACCESS_HPP
#define VIRTUAL_MEMBER_ACCESS_HPP

/*
	These are for determining how to appropriatly decompile the accessing of
	virtual members.
*/

class AbstractA {
protected:
	int abstract_a_data;

	AbstractA() {
		std::cout << "AbstractA Constructor";
	};
	virtual ~AbstractA()
	{
		std::cout << "AbstractA virtual Destructor";
	}

public:
	virtual void abstract_a_foo() = 0;
	virtual int access();
};

class A {

protected:
	int a_data;

public:
	A() {
		std::cout << "A Constructor";
	};
	virtual ~A()
	{
		std::cout << "A virtual Destructor";
	}
	virtual int access();
};

class B : virtual public A {

protected:
	int b_data;

public:
	B() {
		std::cout << "B Constructor";
	}
	virtual ~B()
	{
		std::cout << "B virtual Destructor";
	}
	virtual int access();
};

class C : virtual public A {

protected:
	int c_data;

public:
	C() {
		std::cout << "C Constructor";
	}
	virtual ~C() {
		std::cout << "C virtual Destructor";
	};
	virtual int access();
};

class D : public B, public C {

protected:
	int d_data;

public:
	D()
	{
		std::cout << "D Constructor";
	}
	virtual ~D()
	{
		std::cout << "D virtual Destructor";
	}
	virtual int access();
};

class E : public AbstractA {

protected:
	int e_data;

public:
	E() {
		std::cout << "E Constructor";
	};
	virtual ~E() {
		std::cout << "E virtual Destructor";
	}
	void abstract_a_foo();
	virtual int access();
};

class F : virtual public AbstractA {

protected:
	int f_data;

public:
	F() {
		std::cout << "F Constructor";
	}
	virtual ~F() {
		std::cout << "F virtual Destructor";
	}
	void abstract_a_foo();
	virtual int access();
};

class G : public E, public F {

protected:
	int g_data;

public:
	G() {
		std::cout << "G Constructor";
	}
	virtual ~G() {
		std::cout << "G virtual Destructor";
	}
	virtual int access();

};

class H : public virtual E, public virtual F {

protected:
	int h_data;

public:
	H() {
		std::cout << "H Constructor";
	}
	virtual ~H() {
		std::cout << "H virtual Destructor";
	}
	virtual int access();
};

#endif // VIRTUAL_MEMBER_ACCESS_HPP