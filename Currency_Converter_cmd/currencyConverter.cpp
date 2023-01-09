#include <iostream>
#include <map>
#include <fstream> // for reading from text file
#include <sstream> // for parsing lines in text file

using namespace std;

map<string, double> currencyRates;

// Function to read conversion rates from text file and store in the map
void readRatesFromFile(string fileName) {
// Open the text file in input mode
ifstream file(fileName);
// Check if the file was successfully opened
if (!file.is_open()) {
cout << "Error: Could not open file '" << fileName << "'" << endl;
return;
}

// Read each line of the file
string line;
while (getline(file, line)) {
    // Use a stringstream to parse the line
    stringstream lineStream(line);

    // Read the currency code and rate from the line
    string currency;
    double rate;
    lineStream >> currency >> rate;

    // Store the currency and rate in the map
    currencyRates[currency] = rate;
}
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments was passed
    if (argc != 4) {
        cout << "Usage: currency_converter input_currency output_currency amount" << endl;
        return 1;
    }

    // Read the conversion rates from the text file "rates.txt"
    readRatesFromFile("rates.txt");

    // Get the input and output currencies and the amount from the command line arguments
    string inputCurrency = argv[1];
    string outputCurrency = argv[2];
    double amount = atof(argv[3]);

    // Check if the input currency is valid
    if (currencyRates.count(inputCurrency) == 0) {
        cout << "Error: Invalid input currency" << endl;
        return 1;
    }

    // Check if the output currency is valid
    if (currencyRates.count(outputCurrency) == 0) {
        cout << "Error: Invalid output currency" << endl;
        return 1;
    }

    // Check if the amount is a valid number
    if (amount <= 0) {
        cout << "Error: Invalid amount" << endl;
        return 1;
    }

    // Check if the amount is within the desired range
    const double MIN_AMOUNT = 1.0;
    const double MAX_AMOUNT = 1000000.0;
    if (amount < MIN_AMOUNT || amount > MAX_AMOUNT) {
        cout << "Error: Amount must be between " << MIN_AMOUNT << " and " << MAX_AMOUNT << endl;
        return 1;
    }

    // Calculate the converted amount
    double convertedAmount = amount * currencyRates[outputCurrency] / currencyRates[inputCurrency];

    // Print the result
    cout << amount << " " << inputCurrency << " would be " << convertedAmount << " " << outputCurrency << " on 2023-01-06" << endl;

    return 0;
}
