#include "authentication.hpp"

bool authenticateUser(const std::string& username, const std::string& password) {
    // Simple hardcoded check for demonstration
    return username == "admin" && password == "securepassword";
}
