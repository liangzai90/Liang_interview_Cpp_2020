#include "builder.h"
#include <iostream>

using namespace std;

//----------------------------------------------
// ConcreateBuilder1
//----------------------------------------------
void ConcreateBuilder1::BuilderPartA()
{
    cout << "BuilderPartA by ConcreateBuilder1." << endl;
}

void ConcreateBuilder1::BuilderPartB()
{
    cout << "BuilderPartB by ConcreateBuilder1." << endl;
}



//----------------------------------------------
// ConcreateBuilder2
//----------------------------------------------
void ConcreateBuilder2::BuilderPartA()
{
    cout << "BuilderPartA by ConcreateBuilder2." << endl;
}

void ConcreateBuilder2::BuilderPartB()
{
    cout << "BuilderPartB by ConcreateBuilder2." << endl;
}



//----------------------------------------------
// Director
//----------------------------------------------
Director::Director(Builder* pBuilder) :m_pBuilder(pBuilder)
{
    // 
}

Director::~Director()
{
    delete m_pBuilder;
    m_pBuilder = NULL;
}

void Director::Construct()
{
    m_pBuilder->BuilderPartA();
    m_pBuilder->BuilderPartB();
}
