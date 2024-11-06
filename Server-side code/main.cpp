#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "utils.hpp"
#include "logging.hpp"

void displayHTMLHeader() {
    std::cout << "Content-type: text/html\n\n";
    std::cout << "<!DOCTYPE html><html><head><title>Outlier Detection</title>";
    std::cout << "<link rel='stylesheet' href='/web/styles.css'></head><body>";
}

void displayHTMLFooter() {
    std::cout << "</body></html>";
}

// Function to parse multipart form data and validate input format
std::vector<double> parseFileInput() {
    std::string line;
    std::vector<double> transactions;

    while (std::getline(std::cin, line)) {
        std::istringstream ss(line);
        double value;
        bool validData = true;

        while (ss >> value) {
            if (ss.fail()) {
                validData = false;
                break;
            }
            transactions.push_back(value);
        }

        if (!validData) {
            throw std::runtime_error("Invalid data format. Please ensure the file contains only numerical values.");
        }
    }

    return transactions;
}

int main() {
    displayHTMLHeader();

    try {
        std::vector<double> transactions = parseFileInput();
        logInfo("File parsed successfully with " + std::to_string(transactions.size()) + " transactions.");

        if (transactions.empty()) {
            throw std::runtime_error("No data found or file is empty.");
        }

        double mean = calculateMean(transactions);
        double stdDev = calculateStdDev(transactions, mean);

        std::cout << "<h1>Outlier Detection Results</h1>";
        std::cout << "<table><tr><th>Transaction Index</th><th>Amount</th><th>Status</th></tr>";

        for (size_t i = 0; i < transactions.size(); ++i) {
            std::cout << "<tr><td>" << i << "</td><td>$" << transactions[i] << "</td>";
            if (isOutlier(transactions[i], mean, stdDev)) {
                std::cout << "<td class='outlier'>Outlier</td>";
            } else {
                std::cout << "<td>Normal</td>";
            }
            std::cout << "</tr>";
        }

        std::cout << "</table>";
    } catch (const std::exception& e) {
        logError(e.what());
        std::cout << "<p class='error'>Error: " << e.what() << "</p>";
    } catch (...) {
        logError("Unknown error occurred.");
        std::cout << "<p class='error'>An unknown error occurred.</p>";
    }

    displayHTMLFooter();
    return 0;
}
