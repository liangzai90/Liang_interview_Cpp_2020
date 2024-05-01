#ifndef _HenryS1Server_H_
#define _HenryS1Server_H_

#include <iostream>
#include "servant/Application.h"

using namespace tars;

/**
 *
 **/
class HenryS1Server : public Application
{
public:
    /**
     *
     **/
    virtual ~HenryS1Server() {};

    /**
     *
     **/
    virtual void initialize();

    /**
     *
     **/
    virtual void destroyApp();
};

extern HenryS1Server g_app;

////////////////////////////////////////////
#endif
