#include <iostream>

using namespace std;

typedef enum ProductTypeTag
{
    TypeA,
    TypeB,
    TypeC
}ProductType;

// Here is the product class
class Product
{
public:
    virtual void Show() = 0;
    virtual ~Product()
    {
        //�������û������������������̳�ʱ��ͨ�����������󲻻������������
    }
};



class ProductA: public Product
{
public:
    void Show()
    {
        cout << "I'm Product===========A" << endl;
    }
    ~ProductA()
    {
        cout << "Destructor Product====A" << endl;
    }
};

class ProductB: public Product
{
public:
    void Show()
    {
        cout << "I'm Product===========B" << endl;
    }
    ~ProductB()
    {
        cout << "Destructor Product====B" << endl;
    }
};

class ProductC: public Product
{
public:
    void Show()
    {
        cout << "I'm Product===========C" << endl;
    }
    ~ProductC()
    {
        cout << "Destructor Product====C" << endl;
    }
};

//������
class Factory
{
public:
    Product* CreateProduct(ProductType type)
    {
        switch (type)
        {
            case TypeA:
                return new ProductA();
            case TypeB:
                return new ProductB();
            case TypeC:
                return new ProductC();

            default:
                return nullptr;
        }
    }

    ~Factory()
    {
        cout << "Destructor Factory==========" << endl;
    }
};


int main()
{
    //ʹ������ָ��
    unique_ptr<Factory> factory(new Factory());
    unique_ptr<Product> productA(factory->CreateProduct(TypeA));
    productA->Show();

    unique_ptr<Product> productB(factory->CreateProduct(TypeB));
    productB->Show();

    unique_ptr<Product> productC(factory->CreateProduct(TypeC));
    productC->Show();

//    Product *productA = factory->CreateProduct(TypeA);
//    productA->Show();
//    delete productA;
//    productA = nullptr;
    cout << "Hello World!" << endl;
    return 0;
}








