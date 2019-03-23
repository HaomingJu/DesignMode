#include <iostream>
#include <memory>

// interface
enum class TYPE_PRODUCT
{
    TYPE_PRODUCT_A,
    TYPE_PRODUCT_B,
    TYPE_PRODUCT_C
};

class VirtualBaseProduct
{
  public:
    virtual void show() = 0;
    virtual ~VirtualBaseProduct(){};
};
class Product_A : public virtual VirtualBaseProduct
{
  public:
    void show();
};
class Product_B : public virtual VirtualBaseProduct
{
  public:
    void show();
};
class Product_C : public virtual VirtualBaseProduct
{
  public:
    void show();
};
class SimpleFactory
{
  public:
    std::shared_ptr<VirtualBaseProduct> CreateProduct(TYPE_PRODUCT);
};


// implement
void Product_A::show()
{
    std::cout << "hello Product_A" << std::endl;
};
void Product_B::show()
{
    std::cout << "hello Product_B" << std::endl;
};
void Product_C::show()
{
    std::cout << "hello Product_C" << std::endl;
};

std::shared_ptr<VirtualBaseProduct> SimpleFactory::CreateProduct(TYPE_PRODUCT type_product)
{
    switch(type_product)
    {
        case TYPE_PRODUCT::TYPE_PRODUCT_A:
        {
            std::shared_ptr<VirtualBaseProduct> smart_ptr(new Product_A());
            return smart_ptr;
            break;
        }
        case TYPE_PRODUCT::TYPE_PRODUCT_B:
        {
            std::shared_ptr<VirtualBaseProduct> smart_ptr(new Product_B());
            return smart_ptr;
            break;
        }
        case TYPE_PRODUCT::TYPE_PRODUCT_C:
        {
            std::shared_ptr<VirtualBaseProduct> smart_ptr(new Product_C());
            return smart_ptr;
            break;
        }
        default:
        {
            std::shared_ptr<VirtualBaseProduct> smart_ptr(new Product_A());
            return smart_ptr;
            break;
        }
    }
};

int main(int argc, char** argv)
{
    SimpleFactory factory;
    std::shared_ptr<VirtualBaseProduct> product_a = factory.CreateProduct(TYPE_PRODUCT::TYPE_PRODUCT_A);
    std::shared_ptr<VirtualBaseProduct> product_b = factory.CreateProduct(TYPE_PRODUCT::TYPE_PRODUCT_B);
    std::shared_ptr<VirtualBaseProduct> product_c = factory.CreateProduct(TYPE_PRODUCT::TYPE_PRODUCT_C);
    product_a->show();
    product_b->show();
    product_c->show();
    return 0;
}
