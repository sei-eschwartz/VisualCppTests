// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Base {
protected:
	int data_;
};
class Der1 : public virtual Base {
public:
	Der1() : Base() {}
	virtual void TestFunctionA();
	virtual void TestFunctionB();
};
class Der2 : public virtual Base {
public:
	Der2() : Base() {}
	void TestFunctionC() {}
	virtual void TestFunctionD();
};
class Join : public Der1, public Der2 {
public:
	Join() : Der1(), Der2() {}
	void method() {
		data_ = 1; 
	}
	void TestFunctionA() {}
	void TestFunctionB() {}
	void TestFunctionD() {}
};

class Base2 {
public:
	Base2(int data) { data_ = data; }
	Base2() {}

protected:
	int data_;
};
class The1 : public virtual Base2 {
public:
	The1(int data, string data2) : Base2(data) { data2_ = data2; }
	virtual void NewTestFunctionA();
	virtual void NewTestFunctionB();

protected:
	string data2_;
};
class The2 : public virtual Base2 {
public:
	The2(int data, float data2, double data3) : Base2(data) {
		data2_ = data2;
		data3_ = data3;
	}
	void NewTestFunctionC() {}
	virtual void NewTestFunctionD();

protected:
	float data2_;
	double data3_;
};
class Join2 : public The1, public The2 {
public:
	Join2(int data, float data2, double data3, string data4)
		: The2(data, data2, data3), The1(data, data4), Base2(data) {}
	void method() {
		data_ = 1;
	}
	void NewTestFunctionA() {
		The1::data2_ = "Hello World";
		The2::data2_ = 1.2345;
	}
	void NewTestFunctionB() {}
	void NewTestFunctionC() {}
	void NewTestFunctionD() {}

protected:
	int myData;
	string string;
	float floatingPoint;
};

class SuperJoin : public virtual Join, public Join2 {
public:
	SuperJoin(int data, float data2, double data3, std::string data4)
		: Join(), Join2(data, data2, data3, data4) {
		The1::data2_ = "SuperJoin Constructor";
		The2::data2_ = 5.678;
	}
	~SuperJoin() {}
	void NewTestFunctionA() {
		myData = 55555;
		string = "ABC";
		floatingPoint = 8.76544;
	}
	void NewTestFunctionB() {}
	void NewTestFunctionC() {}
	void NewTestFunctionD() {}
	void TestFunctionA() {}
	void TestFunctionB() {}
	void TestFunctionD() {}
};

int main() {
	Join* j = new Join();
	Base* b = j;

	SuperJoin* sj = new SuperJoin(10, 20.5, 1.4567777, "Test String");
	delete sj;
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

void Der1::TestFunctionA()
{
}

void Der1::TestFunctionB()
{
}

void The1::NewTestFunctionA()
{
}

void The1::NewTestFunctionB()
{
}

void Der2::TestFunctionD()
{
}

void The2::NewTestFunctionD()
{
}
