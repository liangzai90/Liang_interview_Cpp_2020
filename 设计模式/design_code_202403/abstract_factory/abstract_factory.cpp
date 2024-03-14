#include <iostream>
#include "abstract_factory.h"

using namespace std;


//---------------------------------------------------
// ConcreateProductA1 
//---------------------------------------------------
ConcreateProductA1::ConcreateProductA1()
{
    cout << "construction of ConcreateProductA1." << endl;
}

ConcreateProductA1::~ConcreateProductA1()
{
    cout << "destruction of ConcreateProductA1." << endl;
}



//---------------------------------------------------
// ConcreateProductA2
//---------------------------------------------------
ConcreateProductA2::ConcreateProductA2()
{
    cout << "construction of ConcreateProductA2." << endl;
}

ConcreateProductA2::~ConcreateProductA2()
{
    cout << "destruction of ConcreateProductA2." << endl;
}


//---------------------------------------------------
// ConcreateProductB1
//---------------------------------------------------
ConcreateProductB1::ConcreateProductB1()
{
    cout << "construction of ConcreateProductB1." << endl;
}

ConcreateProductB1::~ConcreateProductB1()
{
    cout << "destruction of ConcreateProductB1." << endl;
}


//---------------------------------------------------
// ConcreateProductB2
//---------------------------------------------------
ConcreateProductB2::ConcreateProductB2()
{
    cout << "construction of ConcreateProductB2." << endl;
}

ConcreateProductB2::~ConcreateProductB2()
{
    cout << "destruction of ConcreateProductB2." << endl;
}



//---------------------------------------------------
// ConcreateFactory1
//---------------------------------------------------
ConcreateFactory1::ConcreateFactory1()
{
    cout << "construction of ConcreateFactory1." << endl;
}

ConcreateFactory1::~ConcreateFactory1()
{
    cout << "destruction of ConcreateFactory1." << endl;
}

AbstractProductA* ConcreateFactory1::CreateProductA()
{
    return new ConcreateProductA1();
}

AbstractProductB* ConcreateFactory1::CreateProductB()
{
    return new ConcreateProductB1();
}

//---------------------------------------------------
// ConcreateFactory2
//---------------------------------------------------
ConcreateFactory2::ConcreateFactory2()
{
    cout << "construction of ConcreateFactory2." << endl;
}

ConcreateFactory2::~ConcreateFactory2()
{
    cout << "destruction of ConcreateFactory2." << endl;
}

AbstractProductA* ConcreateFactory2::CreateProductA()
{
    return new ConcreateProductA2();
}

AbstractProductB* ConcreateFactory2::CreateProductB()
{
    return new ConcreateProductB2();
}


