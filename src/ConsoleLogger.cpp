#include "ConsoleLogger.hpp"

ConsoleLogger::ConsoleLogger() : currentLogLevel(LogLevel::INFO) {}

void ConsoleLogger::log(const std::string& message, LogLevel level) {
    if (level >= currentLogLevel) {
        switch (level) {
            case LogLevel::INFO:
                std::cout << "[INFO] " << message << std::endl;
                break;
            case LogLevel::WARNING:
                std::cout << "[WARNING] " << message << std::endl;
                break;
            case LogLevel::ERROR:
                std::cout << "[ERROR] " << message << std::endl;
                break;
        }
    }
}

void ConsoleLogger::setLogLevel(LogLevel level) {
    currentLogLevel = level;
}