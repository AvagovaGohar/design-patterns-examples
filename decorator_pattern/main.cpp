#include "decorator_pattern.h"

int main()
{
	IBevarageBase* bev = new Milk(new Chokolate(new Tea));
	std::cout << bev->get_cost() << '\n';
	std::cout << bev->get_name() << '\n';
	delete bev;
}
