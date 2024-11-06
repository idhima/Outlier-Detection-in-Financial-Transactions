#include "logging.hpp"
#include <fstream>

void logError(const std::string& message) {
    std::ofstream logFile("logs/error.log", std::ios_base::app);
    if (logFile.is_open()) {
        logFile << "[ERROR] " << message << "\n";
    }
}

void logInfo(const std::string& message) {
    std::ofstream logFile("logs/info.log", std::ios_base::app);
    if (logFile.is_open()) {
        logFile << "[INFO] " << message << "\n";
    }
}
