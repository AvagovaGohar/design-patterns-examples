#include <iostream>
#include <string>
#include <vector>
#ifndef STRATEGY_P
#define STRATEGY_P

//все виртуальные функции, которые в дальнейшем будут использоваться в других классах
class IQuack {
public:
    virtual ~IQuack()
    {

    }
    virtual void _quack() = 0;
};
class IFly {
public:
    virtual ~IFly()
    {

    }
    virtual void _fly() = 0;
};
//
class SimpleQuack : public IQuack {
public:
    virtual ~SimpleQuack()
    {

    }
    void _quack()override {
        std::cout << "simple quack\n";
    }
};
class NoQuack : public IQuack {
public:
    virtual ~NoQuack()
    {

    }
    void _quack()override {}
};

class JustFlying : public IFly {
public:
    virtual ~JustFlying()
    {

    }
    void _fly()override {
        std::cout << "i'm flying quack\n";
    }
};
class NoFly : public IFly {
public:
    virtual ~NoFly()
    {

    }
    void _fly()override {}
};
//можно создать разные типы функций как quack(), так и fly()

class IBaseDuck {
protected:
    IQuack* quacking;
    IFly* flying;
public:
    virtual ~IBaseDuck()
    {
        delete quacking;
        delete flying;
    }
    IBaseDuck()// конструктор, что ставит по умолчанию(SimpleQuack & JustFlying)quacking и flying указатели. Можно еще создать функции для перезаписи указателей на новые классы
    {
        quacking = new  SimpleQuack;
        flying = new JustFlying;
    }
    void fly(){
        flying->_fly();
    }
    void quack() {
        quacking->_quack();
    }
    void swim() {
        std::cout << "swiming\n";
    }
};

class SimpleDuck : public IBaseDuck {
public:
    virtual ~SimpleDuck()
    {

    }
    SimpleDuck()
    {
        
    }
};
class WoodDuck : public IBaseDuck {
public:
    virtual ~WoodDuck()
    {

    }
    WoodDuck()
    {
        delete quacking;
        delete flying;
        quacking = new NoQuack;
        flying = new NoFly;
    }
};
#endif //STRATEGY_P
