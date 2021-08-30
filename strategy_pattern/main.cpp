#include "strategy_pattern.h"

int main()
{
    SimpleDuck* simple = new SimpleDuck;
    simple->quack();
    simple->fly();
    simple->swim();
    delete simple;
    std::cout << '\n';
    WoodDuck* wood = new WoodDuck;
    wood->quack();
    wood->fly();
    wood->swim();
    delete wood;
}
