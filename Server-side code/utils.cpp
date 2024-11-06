#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>

std::vector<double> loadTransactions(const std::string& filename) {
    std::vector<double> transactions;
    std::ifstream file(filename);
    double value;

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    while (file >> value) {
        transactions.push_back(value);
    }

    file.close();
    return transactions;
}

double calculateMean(const std::vector<double>& data) {
    double sum = 0.0;
    for (double num : data) {
        sum += num;
    }
    return sum / data.size();
}

double calculateStdDev(const std::vector<double>& data, double mean) {
    double variance = 0.0;
    for (double num : data) {
        variance += (num - mean) * (num - mean);
    }
    return std::sqrt(variance / data.size());
}

bool isOutlier(double value, double mean, double stdDev) {
    double zScore = (value - mean) / stdDev;
    return std::abs(zScore) > 3; // Common threshold for outlier detection
}
