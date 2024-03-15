#include "prototype.h"
#include <iostream>

using namespace std;



//-------------------------------------------------------------
// Prototype
//-------------------------------------------------------------
void Prototype::Print03()
{
    cout << "Prototype Print03." << endl;
}

//-------------------------------------------------------------
// ConcreatePrototype1
//-------------------------------------------------------------
ConcreatePrototype1::ConcreatePrototype1()
{
    cout << "construction of ConcreatePrototype1." << endl;
}

ConcreatePrototype1::~ConcreatePrototype1()
{
    cout << "destruction of ConcreatePrototype1." << endl;
}

ConcreatePrototype1::ConcreatePrototype1(const ConcreatePrototype1&)
{
    cout << "copy construction of ConcreatePrototype1" << endl;
}

Prototype* ConcreatePrototype1::Clone()
{
    return new ConcreatePrototype1(*this);
}

void ConcreatePrototype1::Print01()
{
    cout << "ConcreatePrototype1 print01." << endl;
}

void ConcreatePrototype1::Print02()
{
    cout << "ConcreatePrototype1 print02." << endl;
}

// void ConcreatePrototype1::Print03()
// {
//     cout << "ConcreatePrototype1 Print03." << endl;
// }



//-------------------------------------------------------------
// ConcreatePrototype2
//-------------------------------------------------------------
ConcreatePrototype2::ConcreatePrototype2()
{
    cout << "construct of ConcreatePrototype2." << endl;
}

ConcreatePrototype2::~ConcreatePrototype2()
{
    cout << "destruction of ConcreatePrototype2." << endl;
}

ConcreatePrototype2::ConcreatePrototype2(const ConcreatePrototype2&)
{
    cout << "copy construction of ConcreatePrototype2." << endl;
}

Prototype* ConcreatePrototype2::Clone()
{
    return new ConcreatePrototype2(*this);
}

void ConcreatePrototype2::Print01()
{
    cout << "ConcreatePrototype2 print01." << endl;
}

void ConcreatePrototype2::Print02()
{
    cout << "ConcreatePrototype2 print02." << endl;
}

void ConcreatePrototype2::Print03()
{
    cout << "ConcreatePrototype2 Print03." << endl;
}







