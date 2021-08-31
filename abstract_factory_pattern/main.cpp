#include "abstract_factory_pattern"

int main()
{
	AbstractFactory* factory_m = new ModernFactory;
	IChair* ch = factory_m->create_chair();
	std::cout << ch->get_name_of_chair();
	delete ch;
	delete factory_m;

	AbstractFactory* factory_w= new WoodFactory;
	ITable* tb = factory_w->create_table();
	std::cout << tb->get_name_of_table();
	delete tb;
	delete factory_w;
	
}
