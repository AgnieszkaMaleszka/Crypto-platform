#pragma once

#include <string>
#include <map>
#include<iostream>
using namespace std;

class Bank
{
protected:
    double balance;
    string currency;
    map<string, double> cryptoBalances;

public:
    Bank();
    Bank(double initialBalance, string mainCurrency, const map<string, double> &initialCryptoBalances);
    Bank(double initialBalance, string mainCurrency);
    ~Bank();

    map<string, double> getCryptoBalances();
    void updateCryptoBalance(string currency, int num);
    string getAccountCurrency();
    double getBalance();
    double operator+(double payment);
    double operator-(double payment);
    double getCryptoBalance(string cryptoCurrency);
    void checkCryptos();
};
