#ifndef CONSOLELOGGER_HPP
#define CONSOLELOGGER_HPP

#include "ILogger.hpp"
#include <iostream>

class ConsoleLogger : public ILogger {
private:
    LogLevel currentLogLevel;

public:
    ConsoleLogger();
    void log(const std::string& message, LogLevel level) override;
    void setLogLevel(LogLevel level) override;
};

#endif // CONSOLELOGGER_HPP