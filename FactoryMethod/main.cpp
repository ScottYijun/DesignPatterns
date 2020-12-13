#include <iostream>

using namespace std;

class Product
{
public:
    virtual void ConcreteProduct() = 0;
    virtual ~Product() { }
};

class CPUProduct: public Product
{
public:
    void ConcreteProduct()
    {
        cout << "I'm CPU ===============Product" << endl;
    }

    ~CPUProduct()
    {
        cout << "destructor ==========CPUProduct" << endl;
    }
};

class ScreenProduct: public Product
{
public:
    void ConcreteProduct()
    {
        cout << "I'm Screen ============Product" << endl;
    }

    ~ScreenProduct()
    {
        cout << "destructor ==========ScreenProduct" << endl;
    }
};

class Factory
{
public:
    virtual Product* CreateProduct() = 0;
    virtual ~Factory() { }
};

class CPUFactory: public Factory
{
public:
    Product * CreateProduct()
    {
        return new CPUProduct();
    }
    ~CPUFactory()
    {
        cout << "destructor ==========CPUFactory" << endl;
    }
};

class ScreenFactory: public Factory
{
public:
    Product * CreateProduct()
    {
        return new ScreenProduct();
    }
    ~ScreenFactory()
    {
        cout << "destructor ==========ScreenFactory" << endl;
    }
};

int main()
{
    unique_ptr<Factory> cpuFactory(new CPUFactory());
    unique_ptr<Product> cpuProduct(cpuFactory->CreateProduct());
    cpuProduct->ConcreteProduct();

    unique_ptr<Factory> screenFactory(new ScreenFactory());
    unique_ptr<Product> screenProduct(screenFactory->CreateProduct());
    screenProduct->ConcreteProduct();

    cout << "Hello World!" << endl;
    return 0;
}
