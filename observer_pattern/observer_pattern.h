#ifndef OBSERVER_P
#define OBSERVER_P

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class IObject { // интерфейс получателя
public:
	virtual ~IObject()
	{

	}
	virtual void update(std::string&) = 0;
};

class ISubject { // интерфейс отправителя 
public:
	virtual ~ISubject()
	{

	}
	virtual void Add(IObject*) = 0;
	virtual void Remove(IObject*) = 0;
	virtual void Notify() = 0;
};

class Subject : public ISubject{ // конкретный отправитель
public:
	~Subject()override
	{

	}
	void Add(IObject* ob)override {
		obs.push_back(ob);
	}
	void Remove(IObject* ob)override {
		auto it = std::remove(obs.begin(), obs.end(), ob);
		obs.erase(it);
	}
	void Notify() {
		for (const auto& a : obs)
		{
			a->update(message);
		}
	}
	void UpdateMessage(const std::string& ss) {
		message = ss;
		Notify();
	}
private:
	std::string message;
	std::vector<IObject*> obs;
};

class Object : public IObject{ // конкретный получатель(их может быть много)
public:
	~Object()override
	{

	}
	Object(Subject* sub)
	{
		cur_sub = sub;
	}
	void update(std::string& ss)override {
		message_from_sub = ss;
		std::cout << ss<<'\n';
	}
	void Add_Me() {
		cur_sub->Add(this);
	}
	void Remove_Me() {
		cur_sub->Remove(this);
	}
private:
	std::string message_from_sub;
	Subject* cur_sub;
};
#endif // OBSERVER_P
