#include "report_generator.hpp"
#include <fstream>

void generateReport(const std::vector<double>& transactions, const std::string& reportPath) {
    std::ofstream report(reportPath);
    if (!report.is_open()) {
        throw std::runtime_error("Unable to open report file for writing.");
    }

    report << "Transaction Report\n";
    report << "Index,Amount,Status\n";
    for (size_t i = 0; i < transactions.size(); ++i) {
        report << i << "," << transactions[i] << "," << (isOutlier(transactions[i], mean, stdDev) ? "Outlier" : "Normal") << "\n";
    }
    report.close();
}
