#ifndef  __VISITOR_H__
#define  __VISITOR_H__

class Visitor;

class Element
{
public:
    virtual ~Element(){};

    virtual void Accept(Visitor& rVisitor) = 0;

protected:
    Element() {};
};


class ConcreateElementA : public Element
{
public:
    ConcreateElementA() {};
    virtual ~ConcreateElementA() {};

    virtual void Accept(Visitor& rVisitor);
};

class ConcreateElementB : public Element
{
public:
    ConcreateElementB() {};
    virtual ~ConcreateElementB() {};

    virtual void Accept(Visitor& rVisitor);
};

class Visitor
{
public:
    virtual ~Visitor() {};

    virtual void VisitConcreateElementA(ConcreateElementA* pConcreateElementA) = 0;
    virtual void VisitConcreateElementB(ConcreateElementB* pConcreateElementB) = 0;

protected:
    Visitor() {};
};

class ConcreateVisitorA : public Visitor
{
public:
    ConcreateVisitorA() {};
    virtual ~ConcreateVisitorA() {};

    virtual void VisitConcreateElementA(ConcreateElementA* pConcreateElementA);
    virtual void VisitConcreateElementB(ConcreateElementB* pConcreateElementB);
};

class ConcreateVisitorB : public Visitor
{
public:
    ConcreateVisitorB() {};
    virtual ~ConcreateVisitorB() {};

    virtual void VisitConcreateElementA(ConcreateElementA* pConcreateElementA);
    virtual void VisitConcreateElementB(ConcreateElementB* pConcreateElementB);
};



#endif 