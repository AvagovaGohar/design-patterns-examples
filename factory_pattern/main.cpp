#include "factory_pattern"

int main()
{
	IFactory* factory = new Product1Creator;
	IProduct* prod = factory->create_product();
	prod->set_info("new message");
	std::cout<< prod->get_info();
	delete prod;
	delete factory;
}
