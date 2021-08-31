#ifndef DECORATOR_P
#define DECORATOR_P

#include <iostream>
#include <string>

class IBevarageBase {
public:
	virtual ~IBevarageBase()
	{
	}
	virtual std::string get_name() = 0;
	virtual int get_cost() = 0;
};

class Tea : public IBevarageBase{
public:
	~Tea()override
	{
	}
	std::string get_name()override {
		return name;
	}
	int get_cost()override {
		return cost;
	}
private:
	std::string name = "Tea";
	int cost = 100;
};

class IDecorators:public IBevarageBase {
public:
	virtual ~IDecorators()
	{

	}
};

class Milk :public IDecorators {
public:
	~Milk()override {
		delete bev;
	}
	Milk(IBevarageBase * beverage): bev(beverage)
	{

	}
	std::string get_name()override {
		return bev->get_name() + " Milk";
	}
	int get_cost()override {
		return bev->get_cost() + 20;
	}
private:
	IBevarageBase* bev;
};

class Chokolate :public IDecorators {
public:
	~Chokolate()override {
		delete bev;
	}
	Chokolate(IBevarageBase* beverage) : bev(beverage)
	{

	}
	std::string get_name()override {
		return bev->get_name() + " Chokolate";
	}
	int get_cost()override {
		return bev->get_cost() + 30;
	}
private:
	IBevarageBase* bev;
};


#endif // DECORATOR_P
