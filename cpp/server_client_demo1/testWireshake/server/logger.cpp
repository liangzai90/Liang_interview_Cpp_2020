// Logger.cpp

#include "logger.h"
#include <log4cplus/configurator.h>

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::init(const std::string& filename) {
    log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("/home/henry/workspace/testa/testWireshake/log4cplus.properties"));
    logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(filename));
}

log4cplus::Logger Logger::getLogger() const {
    return logger;
}
