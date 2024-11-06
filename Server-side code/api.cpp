#include <iostream>
#include <fstream>
#include <vector>
#include "utils.hpp"

int main() {
    std::vector<double> transactions = loadTransactions("input.txt");
    // Analysis logic...
    std::cout << "Content-type: application/json\n\n";
    std::cout << "{\"transactions\": [...] }"; // Construct JSON response
    return 0;
}
