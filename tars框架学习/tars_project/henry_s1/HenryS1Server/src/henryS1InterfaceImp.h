#ifndef _henryS1InterfaceImp_H_
#define _henryS1InterfaceImp_H_

#include "servant/Application.h"
#include "henryS1Interface.h"

/**
 *
 *
 */
class henryS1InterfaceImp : public Test::henryS1Interface
{
public:
    /**
     *
     */
    virtual ~henryS1InterfaceImp() {}

    /**
     *
     */
    virtual void initialize();

    /**
     *
     */
    virtual void destroy();

    // 自定义的函数
    string toStockKey(short shtMarket, const string &sCode);

    /**
     * 实现这些接口 
     */
    virtual int test(tars::TarsCurrentPtr current) { return 0;}; 

    virtual tars::Int32 funA1(tars::Int32 x,tars::Int32 y,tars::TarsCurrentPtr _current_);
    virtual void funA2(tars::Int32 x,tars::Int32 y,tars::Int32 &sum,tars::TarsCurrentPtr _current_);

    virtual std::string funB1(const std::string & str1,tars::TarsCurrentPtr _current_);
    virtual void funB2(const std::string & str1,std::string &str2,tars::TarsCurrentPtr _current_);

    virtual tars::Int32 stockPool(const Test::FStockPoolReq & stReq,Test::FStockPoolRsp &stRsp,tars::TarsCurrentPtr _current_);

};
/////////////////////////////////////////////////////
#endif
