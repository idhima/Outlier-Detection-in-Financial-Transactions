#include "model_integration.hpp"
#include <cstdlib>

std::vector<bool> detectAnomaliesUsingML(const std::vector<double>& transactions) {
    // Call a Python script using system() for simplicity (replace with better IPC for real-world use)
    system("python3 ml_model.py input.txt output.txt");
    // Parse output.txt to populate results (outlier flags)
    std::vector<bool> results;
    // Code to parse results from file...
    return results;
}
