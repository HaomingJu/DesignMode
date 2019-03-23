/* 
 * 让低端工厂生产不同种类的低端产品
 * 让高端工厂生产不同种类的高端产品
 */

#include <iostream>
#include <memory>

class AbstactBaseProduct_A;
class AbstactBaseProduct_B;
class AbstractFactory
{
  public:
    virtual std::shared_ptr<AbstactBaseProduct_A> CreateProduct_A() = 0;
    virtual std::shared_ptr<AbstactBaseProduct_B> CreateProduct_B() = 0;
    virtual ~AbstractFactory(){};
};
class Factory_1 : public virtual AbstractFactory
{
  public:
    std::shared_ptr<AbstactBaseProduct_A> CreateProduct_A();
    std::shared_ptr<AbstactBaseProduct_B> CreateProduct_B();
};
class Factory_2 : public virtual AbstractFactory
{
  public:
    std::shared_ptr<AbstactBaseProduct_A> CreateProduct_A();
    std::shared_ptr<AbstactBaseProduct_B> CreateProduct_B();
};


class AbstactBaseProduct_A
{
  public:
    virtual void show() = 0;
    virtual ~AbstactBaseProduct_A(){};
};
class Product_A1 : public virtual AbstactBaseProduct_A
{
  public:
    void show();
};

class Product_A2 : public virtual AbstactBaseProduct_A
{
  public:
    void show();
};

class AbstactBaseProduct_B
{
  public:
    virtual void show() = 0;
    virtual ~AbstactBaseProduct_B(){};
};

class Product_B1 : public virtual AbstactBaseProduct_B
{
  public:
    void show();
};

class Product_B2 : public virtual AbstactBaseProduct_B
{
  public:
    void show();
};

std::shared_ptr<AbstactBaseProduct_A> Factory_1::CreateProduct_A()
{
    std::shared_ptr<AbstactBaseProduct_A> tmp(new Product_A1());
    return tmp;
};
std::shared_ptr<AbstactBaseProduct_B> Factory_1::CreateProduct_B()
{
    std::shared_ptr<AbstactBaseProduct_B> tmp(new Product_B1());
    return tmp;
};

std::shared_ptr<AbstactBaseProduct_A> Factory_2::CreateProduct_A()
{
    std::shared_ptr<AbstactBaseProduct_A> tmp(new Product_A2());
    return tmp;
};
std::shared_ptr<AbstactBaseProduct_B> Factory_2::CreateProduct_B()
{
    std::shared_ptr<AbstactBaseProduct_B> tmp(new Product_B2());
    return tmp;
};

void Product_A1::show(){};
void Product_A2::show(){};
void Product_B1::show(){};
void Product_B2::show(){};

int main(int argc, char** argv)
{
    return 0;
}
