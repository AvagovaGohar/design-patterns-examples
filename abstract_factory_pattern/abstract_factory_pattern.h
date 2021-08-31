#ifndef ABSTRACT_FACTORY_P
#define ABSTRACT_FACTORY_P

#include<iostream>
#include<string>

class IChair {
public:
	virtual ~IChair()
	{

	}
	virtual std::string get_name_of_chair() = 0;
};

class ModernChair :public IChair {
public:
	~ModernChair()override
	{

	}
	std::string get_name_of_chair()override {
		return "Modern Chair\n";
	}
};

class WoodrChair :public IChair {
public:
	~WoodrChair()override
	{

	}
	std::string get_name_of_chair()override {
		return "Wood Chair\n";
	}
};

class ITable {
public:
	virtual ~ITable()
	{

	}
	virtual std::string get_name_of_table() = 0;
};

class ModernTable :public ITable {
public:
	~ModernTable()override
	{

	}
	std::string get_name_of_table()override {
		return "Modern Table\n";
	}
};

class WoodTable :public ITable {
public:
	~WoodTable()override
	{

	}
	std::string get_name_of_table()override {
		return "Wood Table\n";
	}
};

class AbstractFactory {
public:
	virtual ~AbstractFactory()
	{

	}
	virtual IChair* create_chair() = 0;
	virtual ITable* create_table() = 0;
};

class ModernFactory : public AbstractFactory {
public:
	~ModernFactory()override
	{

	}
	IChair* create_chair()override {
		return (new ModernChair);
	}
	ITable* create_table()override {
		return (new ModernTable);
	}

};

class WoodFactory : public AbstractFactory {
public:
	~WoodFactory()override
	{

	}
	IChair* create_chair()override {
		return (new WoodrChair);
	}
	ITable* create_table()override {
		return (new WoodTable);
	}

};
#endif // ABSTRACT_FACTORY_P
