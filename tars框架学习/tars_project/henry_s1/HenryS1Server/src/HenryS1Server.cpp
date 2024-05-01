#include "HenryS1Server.h"
#include "henryS1InterfaceImp.h"

using namespace std;

HenryS1Server g_app;

/////////////////////////////////////////////////////////////////
void
HenryS1Server::initialize()
{
    //initialize application here:
    //...

    addServant<henryS1InterfaceImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".henryS1InterfaceObj");
}
/////////////////////////////////////////////////////////////////
void
HenryS1Server::destroyApp()
{
    //destroy application here:
    //...
}
/////////////////////////////////////////////////////////////////
int
main(int argc, char* argv[])
{
    try
    {
        g_app.main(argc, argv);
        g_app.waitForShutdown();
    }
    catch (std::exception& e)
    {
        cerr << "std::exception:" << e.what() << std::endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << std::endl;
    }
    return -1;
}
/////////////////////////////////////////////////////////////////
