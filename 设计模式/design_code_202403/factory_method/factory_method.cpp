#include <iostream>
#include "factory_method.h"

using namespace std;


//--------------------
// ConcreateProduct
//--------------------
ConcreateProduct::ConcreateProduct()
{
    cout << "construction of ConcreateProduct. " << endl;
}

ConcreateProduct::~ConcreateProduct()
{
    cout << "destruction of ConcreateProduct. " << endl;
}


//--------------------
// Creator
//--------------------
void Creator::AnOperation()
{
    // 设计模式的演示图上，把 Factory 类命名为 Creator.
    // 如果新增了一个 Product，那么就要新增一个 Factory. Product 的创建过程委托给了这个Factory.
    /// 也就是说，一个 Factory 和 Product 是一一对应的关系。 
    Product* p = FactoryMethod();

    // 此处的指针，如果不用的时候，记得释放！
    delete p;

    cout << "An operation of product. " << endl;
}

//--------------------
// ConcreateCreator
//--------------------
ConcreateCreator::ConcreateCreator()
{
    cout << "construction of ConcreateCreator." << endl;
}

ConcreateCreator::~ConcreateCreator()
{
    cout << "destruction of ConcreateCreator." << endl;
}

Product* ConcreateCreator::FactoryMethod()
{
    return new ConcreateProduct();
}

