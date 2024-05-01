#include <iostream>
#include "servant/Communicator.h"
#include "henryS1Interface.h"

using namespace std;
using namespace Test;
using namespace tars;

int main(int argc,char ** argv)
{
    Communicator comm;

    try
    {
        henryS1InterfacePrx prx;
        std::string s1Server = "Test.HenryS1Server.henryS1InterfaceObj@tcp -h 172.25.0.5 -t 60000 -p 10576 -e 0";
        comm.stringToProxy( s1Server, prx);

        try
        {

            {
                int ifunA1Ret =  prx->funA1(10, 20);
                std::cout<<"funA1 ret:"<<ifunA1Ret<<endl;
            }

            {
                int stRsp = 0;
                prx->funA2(10, 30, stRsp);
                std::cout<<"funA2  stRsp:"<<stRsp<<endl;
            }

            {
                std::string stReq = " hello1 tars demo.";
                std::string stRsp = prx->funB1(stReq);
                std::cout<<"funB1  stRsp:"<<stRsp<<endl;
            }

            {
                std::string stReq = " hello2 tars demo.";
                std::string stRsp;
                prx->funB2(stReq, stRsp);
                std::cout<<"funB2  stRsp:"<<stRsp<<endl;
            }

            {
                Test::FStockPoolReq stReq;
                stReq.iMarket = 0;
                stReq.sCode = "002414";
                Test::FStockPoolRsp stRsp;
                int iRet = prx->stockPool(stReq, stRsp);

                if(stRsp.vecStock.size()>0){
                    std::cout<<"stockPool stkKey:"<<stReq.iMarket<< "_"<< stReq.sCode << ", stRsp iSize:"<<stRsp.iSize
                            << ",lTime:"<<stRsp.lTime<<",iDate:"<<stRsp.iDate<<", stkName:"<<stRsp.vecStock[0].sName
                            <<",price:"<<stRsp.vecStock[0].dNowPrice<<",chgRatio:"<<stRsp.vecStock[0].dChgRatio <<endl;
                }
                else{
                    std::cout<<"stockPool stkKey:"<<stReq.iMarket<< "_"<< stReq.sCode << ", stRsp iSize:"<<stRsp.iSize<<",iRet:"<<iRet<<std::endl;
                }
            }


            {
                Test::FStockPoolReq stReq;
                stReq.iMarket = 2;
                stReq.sCode = "000000";
                Test::FStockPoolRsp stRsp;
                int iRet = prx->stockPool(stReq, stRsp);

                if(stRsp.vecStock.size()>0){
                    std::cout<<"stockPool stkKey:"<<stReq.iMarket<< "_"<< stReq.sCode << ", stRsp iSize:"<<stRsp.iSize
                            << ",lTime:"<<stRsp.lTime<<",iDate:"<<stRsp.iDate<<", stkName:"<<stRsp.vecStock[0].sName
                            <<",price:"<<stRsp.vecStock[0].dNowPrice<<",chgRatio:"<<stRsp.vecStock[0].dChgRatio <<endl;
                }
                else{
                    std::cout<<"stockPool stkKey:"<<stReq.iMarket<< "_"<< stReq.sCode << ", stRsp iSize:"<<stRsp.iSize<<",iRet:"<<iRet<<std::endl;
                }
            }

        }
        catch(exception &ex)
        {
            cerr << "ex:" << ex.what() << endl;
        }
        catch(...)
        {
            cerr << "unknown exception." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "exception:" << e.what() << endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << endl;
    }

    return 0;
}