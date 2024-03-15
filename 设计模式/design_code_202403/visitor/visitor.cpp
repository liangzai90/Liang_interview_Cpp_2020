#include "visitor.h"
#include <iostream>

using namespace std;

///--------------------------------------------------------
// ConcreateElementA  
///--------------------------------------------------------
void ConcreateElementA::Accept(Visitor& rVisitor)
{
    rVisitor.VisitConcreateElementA(this);
}


///--------------------------------------------------------
// ConcreateElementB  
///--------------------------------------------------------
void ConcreateElementB::Accept(Visitor& rVisitor)
{
    rVisitor.VisitConcreateElementB(this);
}


///--------------------------------------------------------
// ConcreateVisitorA  
///--------------------------------------------------------
void ConcreateVisitorA::VisitConcreateElementA(ConcreateElementA* pConcreateElementA)
{
    cout << "VisitConcreateElementA by ConcreateVisitorA." << endl;
}

void ConcreateVisitorA::VisitConcreateElementB(ConcreateElementB* pConcreateElementB)
{
    cout << "VisitConcreateElementB by ConcreateVisitorA." << endl;
}


///--------------------------------------------------------
// ConcreateVisitorB  
///--------------------------------------------------------
void ConcreateVisitorB::VisitConcreateElementA(ConcreateElementA* pConcreateElementA)
{
    cout << "VisitConcreateElementA by ConcreateVisitorB..." << endl;
}

void ConcreateVisitorB::VisitConcreateElementB(ConcreateElementB* pConcreateElementB)
{
    cout << "VisitConcreateElementB by ConcreateVisitorB..." << endl;
}


