# Outlier-Detection-in-Financial-Transactions
# Overview
This project implements a system to detect outliers in financial transactions using statistical and machine learning techniques. The system processes transaction data uploaded by users, detects outliers, and provides an interactive web-based interface to display the results.

# Features:
1.Transaction Outlier Detection: Detects outliers in transaction amounts using statistical methods (Z-score) and machine learning (Isolation Forest).
2.User Authentication: Basic login system to secure access.
3.Data Visualization: Graphical representation of transactions and outliers using Chart.js.
4.Downloadable Report: Generates a detailed CSV report of the transaction analysis.
5.RESTful API: Allows integration with other systems.
6.Logging: Tracks user actions and errors for debugging and auditing purposes.


# Getting Started
# Prerequisites:
Before running the project, ensure the following are installed on your system:

*C++ Compiler (e.g., g++ on Linux or MinGW on Windows)
*Python 3.x (for running machine learning models)
*Chart.js (for visualizations, included in the web assets)
*Web Server (Apache, Nginx, or similar to handle CGI)

# Installing Dependencies:
1. Backend (C++ Setup):

Install a C++ compiler (e.g., g++ on Linux or MinGW on Windows).
Ensure the required libraries for file handling and HTTP server are installed.

2. Machine Learning (Python Setup):

* Install the necessary Python libraries:
pip install scikit-learn pandas numpy

3. Frontend:

All frontend dependencies (HTML, CSS, JavaScript) are included in the web/ directory.
You only need a web server to host the front end and run the CGI scripts.

### Running the Project:
1. Compile the C++ Code:
Navigate to the src/ directory and compile the C++ code:
g++ main.cpp utils.cpp logging.cpp report_generator.cpp model_integration.cpp -o /usr/lib/cgi-bin/main.cgi

3. Set Permissions:
Make sure the CGI script is executable:
chmod +x /usr/lib/cgi-bin/main.cgi

3. Setting Up the Web Server:
Ensure your web server is configured to support CGI scripts. You can configure it to point to the /usr/lib/cgi-bin/ directory for CGI scripts.
For Apache, enable CGI by ensuring the following settings in httpd.conf:

ScriptAlias /cgi-bin/ "/usr/lib/cgi-bin/"
AddHandler cgi-script .cgi .pl .py

4. Run the Web Server:
Start the web server, and navigate to the project directory in your browser.

5. Upload Transaction Data:
Once the server is running, open the application in a browser. Upload a text file containing transaction data (one transaction per line). The system will process the file and display results.

6. View Results:
After processing, the web page will display:

A table of transactions with their respective outlier status (normal or outlier).
An interactive bar chart that highlights outliers.
An option to download a CSV report of the analysis.

### Logging
The system maintains logs of all errors and important events. Logs are stored in the logs/ directory:

*error.log: Contains error messages and issues encountered during processing.
*info.log: Tracks successful operations and user actions.

### Machine Learning Integration
The system uses Python's scikit-learn to run an Isolation Forest model for advanced anomaly detection.
You can replace the statistical Z-score method with the machine learning model by modifying the relevant function in src/model_integration.cpp.

### Contributing
Feel free to fork the repository and submit pull requests. Contributions to improve the outlier detection model, add more visualizations, or optimize performance are always welcome.
