#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(nullptr == m_Instance)
        {
            m_Instance = new Singleton();
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


int main()
{
    Singleton *singletion = Singleton::getInstance();
    cout << "singletion->GetData()============" << singletion->GetData() << endl;
    //unique_ptr<Singleton> singletionObj(Singleton::getInstance());
    //cout << "singletionObj->GetData()============" << singletionObj->GetData() << endl;
    Singleton::DestoryInstance();
    cout << "Hello World!" << endl;
    return 0;
}
