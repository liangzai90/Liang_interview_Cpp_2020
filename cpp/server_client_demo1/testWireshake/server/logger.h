// Logger.h

#ifndef LOGGER_H
#define LOGGER_H
#include <log4cplus/loggingmacros.h>
#include <log4cplus/logger.h>

class Logger {
public:
    static Logger& getInstance();
    void init(const std::string& filename);

    log4cplus::Logger getLogger() const;

private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

private:
    log4cplus::Logger logger;
};

#define LOG_INFO(msg) LOG4CPLUS_INFO(Logger::getInstance().getLogger(), msg)
#define LOG_ERROR(msg) LOG4CPLUS_ERROR(Logger::getInstance().getLogger(), msg)

#endif // LOGGER_H
