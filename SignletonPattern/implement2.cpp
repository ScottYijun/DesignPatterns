#include <QCoreApplication>
#include <iostream>
#include <QMutex>

using namespace std;

static QMutex mutex;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(nullptr == m_Instance)
        {
            cout << "mutex.lock()=================" << endl;
            mutex.lock();   //lock²Ù×÷, QMutex
            if(nullptr == m_Instance)
            {
                m_Instance = new Singleton();
            }
            mutex.unlock(); //ÊÍ·Å²Ù×÷  QMutex
            cout << "mutex.unlock()===============" << endl;
        }
        return m_Instance;
    }

    static void DestoryInstance()
    {
        if(nullptr != m_Instance)
        {
            delete m_Instance;
            m_Instance = nullptr;
        }
        cout << "DestoryInstance()============" << endl;
    }

    int GetData()
    {
        return m_nData;
    }

private:
    Singleton()
    {
        m_nData = 25;
    }

    static Singleton *m_Instance;
    int m_nData;
};

Singleton *Singleton::m_Instance = nullptr;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Singleton *singletion = Singleton::getInstance();
    cout << "singletion->GetData()============" << singletion->GetData() << endl;
    Singleton::DestoryInstance();
    cout << "Hello World!" << endl;
    return a.exec();
}
