#include "henryS1InterfaceImp.h"
#include "servant/Application.h"
#include "util/tc_common.h"
#include <unordered_map>
#include <utility>  // for std::make_pair

using namespace std;

//////////////////////////////////////////////////////
void henryS1InterfaceImp::initialize()
{
    //initialize servant here:
    //...
}

//////////////////////////////////////////////////////
void henryS1InterfaceImp::destroy()
{
    //destroy servant here:
    //...
}

string henryS1InterfaceImp::toStockKey(short shtMarket, const string &sCode) 
{
    string sKey;
    sKey += tars::TC_Common::tostr(shtMarket);
    sKey += "_";
    sKey += sCode;
    return sKey;
};


tars::Int32 henryS1InterfaceImp::funA1(tars::Int32 x,tars::Int32 y,tars::TarsCurrentPtr _current_){
    TLOGDEBUG("henryS1InterfaceImp::funA1 x:"<<x<<",y:"<<y<<endl);
    return x+y;
}


void henryS1InterfaceImp::funA2(tars::Int32 x,tars::Int32 y,tars::Int32 &sum,tars::TarsCurrentPtr _current_){
    TLOGDEBUG( __FUNCTION__<<"::funA2 ,line:"<<__LINE__<<", x:"<< x <<", y:"<<y<<endl);
    sum = (x+y)*10;
}

std::string henryS1InterfaceImp::funB1(const std::string & str1,tars::TarsCurrentPtr _current_){
    TLOGDEBUG( __FUNCTION__<<"::funB1 ,line:"<<__LINE__<<", str1:"<< str1 <<endl);
    std::string strRet = " s1 server funB1 return. + " + str1;
    return strRet;
}

void henryS1InterfaceImp::funB2(const std::string & str1,std::string &str2,tars::TarsCurrentPtr _current_){
    str2 = " s1 server funB2 return. + " + str1;
    TLOGDEBUG( __FUNCTION__<<"::funB2 ,line:"<<__LINE__<<", str1:"<< str1 <<",str2:"<<str2<< endl);
}

tars::Int32 henryS1InterfaceImp::stockPool(const Test::FStockPoolReq & stReq,Test::FStockPoolRsp &stRsp,tars::TarsCurrentPtr _current_){
    std::unordered_map<string, Test::FZDStockInfo> mapStock;
    {
        Test::FZDStockInfo oneStk;
        oneStk.iMarket = 1;
        oneStk.sCode = "600000";
        oneStk.sName = "浦发银行";
        oneStk.dNowPrice = 10;
        oneStk.dChgRatio = 8.88;
        mapStock[toStockKey(oneStk.iMarket, oneStk.sCode)] = oneStk;
    }
    {
        Test::FZDStockInfo oneStk;
        oneStk.iMarket = 1;
        oneStk.sCode = "601318";
        oneStk.sName = "中国平安";
        oneStk.dNowPrice = 11;
        oneStk.dChgRatio = 7.88;
        mapStock[toStockKey(oneStk.iMarket, oneStk.sCode)] = oneStk;
    }
    {
        Test::FZDStockInfo oneStk;
        oneStk.iMarket = 1;
        oneStk.sCode = "600914";
        oneStk.sName = "中国移动";
        oneStk.dNowPrice = 12;
        oneStk.dChgRatio = 6.88;
        mapStock[toStockKey(oneStk.iMarket, oneStk.sCode)] = oneStk;
    }

    {
        Test::FZDStockInfo oneStk;
        oneStk.iMarket = 0;
        oneStk.sCode = "000001";
        oneStk.sName = "平安银行";
        oneStk.dNowPrice = 13;
        oneStk.dChgRatio = 5.88;
        mapStock[toStockKey(oneStk.iMarket, oneStk.sCode)] = oneStk;
    }
    {
        Test::FZDStockInfo oneStk;
        oneStk.iMarket = 0;
        oneStk.sCode = "002624";
        oneStk.sName = "完美世界";
        oneStk.dNowPrice = 15;
        oneStk.dChgRatio = 3.88;
        mapStock[toStockKey(oneStk.iMarket, oneStk.sCode)] = oneStk;
    }
    {
        Test::FZDStockInfo oneStk;
        oneStk.iMarket = 0;
        oneStk.sCode = "002414";
        oneStk.sName = "高德红外";
        oneStk.dNowPrice = 16;
        oneStk.dChgRatio = 2.88;
        mapStock[toStockKey(oneStk.iMarket, oneStk.sCode)] = oneStk;
    }

    int iDate = TC_Common::strto<int>(TC_Common::nowdate2str());
    std::string stkKey = toStockKey(stReq.iMarket, stReq.sCode);
    if(mapStock.find(stkKey) != mapStock.end()){
        stRsp.iDate = iDate;
        stRsp.vecStock.push_back(mapStock[stkKey]);
        stRsp.iSize = 1;
        stRsp.lTime = TC_Common::now2ms();
        TLOGDEBUG( __FUNCTION__<<"::stockPool ,line:"<<__LINE__<<", Find One! iDate:"<< iDate <<",lTime:"<< stRsp.lTime <<",stkKey:"<<stkKey<< endl);
    }else{
        stRsp.iDate = iDate;
        stRsp.iSize = 0;
        stRsp.lTime = TC_Common::now2ms();
        TLOGDEBUG( __FUNCTION__<<"::stockPool ,line:"<<__LINE__<<", Not Find! iDate:"<< iDate <<",lTime:"<< stRsp.lTime << endl);
        return -1;
    }
    return 0;
}
