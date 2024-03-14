#include <iostream>
#include "adapter.h"

using namespace std;

//--------------------------------------------
// Adaptee
//--------------------------------------------
Adaptee::Adaptee(){ 
    std::cout<<"----construct Adaptee"<<std::endl;
}

Adaptee::~Adaptee(){
    std::cout<<"----destruct Adaptee"<<std::endl;
}

void Adaptee::SpecialRequest()
{
    cout << "SpecialRequest of Adaptee." << endl;
}


//--------------------------------------------
// Adapter
//--------------------------------------------

Adapter::Adapter(std::shared_ptr<Adaptee> pAdptee) :m_pAdptee(pAdptee)
{
    std::cout<<"Adapter::Adapter construct"<<std::endl;
}

Adapter::~Adapter()
{
    std::cout<<"Adapter::~Adapter destruct " << std::endl;
}

void Adapter::Request()
{
    cout << "Request of Adapter." << endl;
    // 需要判断 m_pAdptee  为空吗？
    m_pAdptee->SpecialRequest();
}



