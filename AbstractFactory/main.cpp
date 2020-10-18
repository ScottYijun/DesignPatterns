#include <iostream>

using namespace std;

class AbstractProductCPU
{
public:
    virtual void show() = 0;
    virtual ~AbstractProductCPU()
    {
        cout << "AbstractProductCPU destructor========this=" << this << endl;
    }
};

class iPhoneProductCPU: public AbstractProductCPU
{
public:
    void show()
    {
        cout << "I'm iPhoneProductCPU================this=" << this << endl;
    }
    ~iPhoneProductCPU()
    {
        cout << "iPhoneProductCPU destructor==========this=" << this << endl;
    }
};

class iMacProductCPU: public AbstractProductCPU
{
public:
    void show()
    {
        cout << "I'm iMacProductCPU=============this=" << this << endl;
    }

    ~iMacProductCPU()
    {
        cout << "iMacProductCPU destructor=======this=" << this << endl;
    }
};

class AbstractProductScreen
{
public:
    virtual void show() = 0;
    virtual ~AbstractProductScreen()
    {
        cout << "AbstractProductScreen destructor=====this=" << this << endl;
    }
};

class iPhoneProductScreen: public AbstractProductScreen
{
public:
    void show()
    {
        cout << "I'm iPhoneProductScreen=============this=" << this << endl;
    }
    ~iPhoneProductScreen()
    {
        cout << "iPhoneProductScreen destructor=======this=" << this << endl;
    }
};

class iMacProductScreen: public AbstractProductScreen
{
public:
    void show()
    {
        cout << "I'm iMacProductScreen=============this=" << this << endl;
    }

    ~iMacProductScreen()
    {
        cout << "iMacProductScreen destructor=======this=" << this << endl;
    }
};

class AbstractFactory
{
public:
    virtual AbstractProductCPU* createCUPFactory() = 0;
    virtual AbstractProductScreen* createScreenFactory() = 0;
    virtual ~AbstractFactory()
    {
        cout << "AbstractFactory destructor===========this=" << this << endl;
    }
};

class iPhoneFactory: public AbstractFactory
{
public:
    AbstractProductCPU* createCUPFactory()
    {
        return new iPhoneProductCPU();
    }
    AbstractProductScreen* createScreenFactory()
    {
        return new iPhoneProductScreen();
    }
    ~iPhoneFactory()
    {
        cout << "iPhoneFactory destructor=============this=" << this << endl;
    }
};

class iMacFactory: public AbstractFactory
{
public:
    AbstractProductCPU* createCUPFactory()
    {
        return new iMacProductCPU();
    }
    AbstractProductScreen* createScreenFactory()
    {
        return new iMacProductScreen();
    }
    ~iMacFactory()
    {
        cout << "iMacFactory destructor=======this=" << this << endl;
    }
};

int main()
{
    //iPhone工厂
    unique_ptr<AbstractFactory> iPhonefactory(new iPhoneFactory());
    unique_ptr<AbstractProductCPU> iPhoneCPU(iPhonefactory->createCUPFactory());
    unique_ptr<AbstractProductScreen> iPhoneScreen(iPhonefactory->createScreenFactory());
    iPhoneCPU->show();
    iPhoneScreen->show();
    cout << endl;
    //iMac工厂
    unique_ptr<AbstractFactory> iMacfactory(new iPhoneFactory());
    unique_ptr<AbstractProductCPU> iMacCPU(iMacfactory->createCUPFactory());
    unique_ptr<AbstractProductScreen> iMacScreen(iMacfactory->createScreenFactory());
    iMacCPU->show();
    iMacScreen->show();
    cout << "Hello World!" << endl << endl;
    return 0;
}
