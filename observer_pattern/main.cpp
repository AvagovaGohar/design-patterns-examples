#include "observer_pattern.h"

int main()
{
	Subject* sub = new Subject;
	Object* ob1 = new Object(sub);
	Object* ob2 = new Object(sub);
	ob1->Add_Me();
	ob2->Add_Me();
	sub->UpdateMessage("new message");
	delete ob2;
	delete ob1;
	delete sub;
}
