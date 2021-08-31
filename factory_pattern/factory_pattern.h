#ifndef FACTORY_P
#define FACTORY_P
#include <iostream>
#include <string>

class IProduct {
public:
	virtual ~IProduct()
	{

	}
	virtual std::string get_info() = 0;
	virtual void set_info(const std::string&) = 0;
};

class ConcreteProduct1 : public IProduct{
public:
	~ConcreteProduct1()override
	{

	}
	std::string get_info() {
		return info;
	}
	void set_info(const std::string& info) {
		this->info = info;
	}
private:
	std::string info;
};

class IFactory {
public:
	virtual ~IFactory()
	{

	}
	virtual IProduct* create_product() = 0;
};

class Product1Creator : public IFactory {
public:
	~Product1Creator()override
	{
		
	}
	IProduct* create_product()override {
		return (new ConcreteProduct1);
	}
	
};
#endif // FACTORY_P
