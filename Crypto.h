#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"
class Crypto
{
private:
    string currency;
    double exchangeRate;
    vector < Transaction <string> > transactionsCryptos;    
    vector<double> prevCourses;

public:
    Crypto();
    Crypto(string newCurrency, double newExchange);

    vector<double> getPrevCourses();

    void addTransaction(Transaction<string> &trans);
    string getCurrency();
    double getExchangeRate();
    vector<Transaction<string>> getTransactions();
    void setTransactions(vector<Transaction<string>> newTransactions);
    void cryptoInfo();
    void changeRate(double newRate);
    double prediction();
    void newTransaction(string mail, string type, double newAmount, double newCourse);
    void showTransactions();
    double profitLoss(double amount);
};
