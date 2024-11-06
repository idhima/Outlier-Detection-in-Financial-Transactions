#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>

// Function to load transactions from a file
std::vector<double> loadTransactions(const std::string& filename);

// Function to calculate the mean of a vector
double calculateMean(const std::vector<double>& data);

// Function to calculate the standard deviation of a vector
double calculateStdDev(const std::vector<double>& data, double mean);

// Function to check if a value is an outlier based on Z-score
bool isOutlier(double value, double mean, double stdDev);

#endif // UTILS_HPP
