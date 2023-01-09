    #include <iostream>
    #include <fstream>
    #include <map>
    #include <vector>

    using namespace std;

 void ReadConversionRates(map<string, double> &currencyRates, vector<string> &currencies) {
    ifstream fin("rates.txt");
    string currency;
    double rate;
    while (fin >> currency >> rate) {
        currencyRates[currency] = rate;
        currencies.push_back(currency);
    }
    fin.close();
}

void PrintCurrencyList(vector<string> &currencies) {
    for (int i = 0; i < currencies.size(); i++) {
        cout << i + 1 << ". " << currencies[i] << endl;
    }
}

int GetInputCurrencyIndex(vector<string> &currencies) {
    int inputCurrency;
    cin >> inputCurrency;
    if (!cin || inputCurrency < 1 || inputCurrency > currencies.size()) {
        cout << "Invalid input. Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return -1;
    }
    return inputCurrency - 1;
}

int GetOutputCurrencyIndex(vector<string> &currencies, int inputCurrency) {
    int outputCurrency;
    cin >> outputCurrency;
    if (!cin || outputCurrency < 1 || outputCurrency > currencies.size() || outputCurrency == inputCurrency) {
        cout << "Invalid input. Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return -1;
    }
    return outputCurrency - 1;
}

double GetAmount() {
    double amount;
    cin >> amount;
    if (amount < 0 || amount > 10000) {
        cout << "Invalid input. Please enter an amount between 0 and 10000." << endl;
        return -1;
    }
    if (!cin) {
        cout << "Invalid input. Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return -1;
    }
    return amount;
}

char GetContinueInput() {
    char continueConversion;
    cin >> continueConversion;
    continueConversion = toupper(continueConversion);
    if (continueConversion != 'Y' && continueConversion != 'N') {
        cout << "Invalid input. Please enter Y or N." << endl;
        return 'I';
    }
    return continueConversion;
}

int main() {
    cout << "Welcome to CCTech Currency converter:" << endl;

    // Read conversion rates from the text file
    map<string, double> currencyRates;
    vector<string> currencies;
    ReadConversionRates(currencyRates, currencies);

    while (true) {
        cout << "Select the input currency from the list" << endl;
        PrintCurrencyList(currencies);

        int inputCurrency = GetInputCurrencyIndex(currencies);
        if (inputCurrency == -1) {
            continue;
        }
        string inputCurrencyCode = currencies[inputCurrency];

        cout << "Select the output currency from the list (should not print the selected input currency at the output)" << endl;
        for (int i = 0; i < currencies.size(); i++) {
            if (i != inputCurrency) {
                cout << i + 1 << ". " << currencies[i] << endl;
            }
        }

        int outputCurrency = GetOutputCurrencyIndex(currencies, inputCurrency);
        if (outputCurrency == -1) {
            continue;
        }
        string outputCurrencyCode = currencies[outputCurrency];

        cout << "Please enter the amount" << endl;
        double amount = GetAmount();
        if (amount == -1) {
            continue;
        }

        double convertedAmount = amount * currencyRates[outputCurrencyCode] / currencyRates[inputCurrencyCode];
        cout << amount << " " << inputCurrencyCode << " would be " << convertedAmount << " " << outputCurrencyCode << " on 2023-01-06" << endl;

        cout << "Do you wish to continue with another conversion (Y/N)" << endl;
        char continueConversion = GetContinueInput();
        if (continueConversion == 'Y') {
            continue;
        }
        else if (continueConversion == 'N') {
            break;
        }
    }
}
