
#include "Bank.h"

using namespace std;

// Bank class constructor
Bank::Bank() : balance(0), currency("$"){}

// Bank class constructor with cryptocurrencies
Bank::Bank(double initialBalance, string mainCurrency, const map<string, double> &initialCryptoBalances)
    : balance(initialBalance), currency(mainCurrency), cryptoBalances(initialCryptoBalances) {}

// Bank class constructor without cryptocurrencies
Bank::Bank(double initialBalance, string mainCurrency) : balance(initialBalance), currency(mainCurrency){}

Bank::~Bank() {}

map<string, double> Bank::getCryptoBalances()
{
    return cryptoBalances;
}

void Bank::updateCryptoBalance(string currency, int num)
{
    if (cryptoBalances.find(currency) != cryptoBalances.end())
    {
        cout << "This currency is already added!\n";
    }
    else
    {
        cryptoBalances[currency] = num;
    }
}

string Bank::getAccountCurrency()
{
    return currency;
}

double Bank::getBalance()
{
    return balance;
}

// Deposit
double Bank::operator+(double payment)
{
    balance += payment;
    return balance;
}
    
// Withdraw
double Bank::operator-(double payment)
{
    if (balance - payment < 0)
        throw "There is not enough money in the account.";
    else
        balance -= payment;
    return balance;
}
    
// Cryptocurrency account balance
double Bank::getCryptoBalance(string cryptoCurrency)
{
    if (cryptoBalances.find(cryptoCurrency) != cryptoBalances.end())
    {
        return cryptoBalances[cryptoCurrency];
    }
    return 0.0;
}

// Displaying all posses cryptobalances 
void Bank::checkCryptos()
{
    cout << "ACCOUNT BALANCE: " << endl;
    cout << currency << " : " << balance << endl;
    for (const auto &entry : cryptoBalances)
    {
        string currency = entry.first;
        double balance = entry.second;
        cout << currency << ": " << balance << endl;
    }
}
