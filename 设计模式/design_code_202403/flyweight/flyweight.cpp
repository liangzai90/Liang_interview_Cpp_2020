#include "flyweight.h"
#include <iostream>

using namespace std;


//---------------------------------------------------
// Flyweight 
//---------------------------------------------------
inline STATE Flyweight::GetIntrinsicState()
{
    return m_State;
}



//---------------------------------------------------
// FlyweightFactory 
//---------------------------------------------------
FlyweightFactory::~FlyweightFactory()
{
    list<Flyweight*>::iterator  iter1, iter2, temp;

    for (iter1 = m_listFlyweight.begin(), iter2 = m_listFlyweight.end(); iter1 != iter2;)
    {
        temp = iter1;
        ++iter1;
        delete(*temp);
    }
    m_listFlyweight.clear();
}

Flyweight* FlyweightFactory::GetFlyweight(const STATE& key)
{
    list<Flyweight*>::iterator  iter1, iter2;
    for (iter1 = m_listFlyweight.begin(), iter2 = m_listFlyweight.end(); iter1 != iter2; ++iter1)
    {
        if ((*iter1)->GetIntrinsicState() == key)
        {
            cout << "The Flyweight:" << key << "already exits." << endl;
            return (*iter1);
        }
    }

    cout << "Creating a new Flyweight:" << key << endl;
    Flyweight* flyweight = new ConcreateFlyweight(key);
    m_listFlyweight.push_back(flyweight);
    return flyweight;
}





//---------------------------------------------------
// ConcreateFlyweight 
//---------------------------------------------------
void ConcreateFlyweight::Operation(STATE& ExtrinsicState)
{
    cout << "ConcreateFlyweight  Operation." << endl;
}



