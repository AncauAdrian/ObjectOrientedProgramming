#include <iostream>
#include <exception>

class B
{
public:
	B() { std::cout << "B{}"; }
	virtual void print() {
		std::cout << "B";
	}
	virtual ~B() { std::cout << "~B()"; }
};
class D : public B
{
public:
	D() { std::cout << "D{}"; }
	void print() override {
		std::cout << "D";
	}
	virtual ~D() { std::cout << "~D()"; }
};int main()
{
	try
	{
		throw std::runtime_error("Test");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}