#include "Crypto.h"
using namespace std;

// required days to predict a course. 10 means that at least 10 days are required to calculate predicted course.
int predictionAccuracy = 10;

Crypto::Crypto() : exchangeRate(0) {}

//constructor adding a currency with name and exchangeRate
Crypto::Crypto(string newCurrency, double newExchange) : currency(newCurrency), exchangeRate(newExchange) {}

vector<double> Crypto::getPrevCourses() { return prevCourses; }

void Crypto::addTransaction(Transaction<string> &trans) { transactionsCryptos.push_back(trans); }

string Crypto::getCurrency() { return currency; }

double Crypto::getExchangeRate() { return exchangeRate; }

vector<Transaction<string>> Crypto::getTransactions() { return transactionsCryptos; }

//adding a new transaction
void Crypto::setTransactions(vector<Transaction<string>> newTransactions) { transactionsCryptos = newTransactions; }  

void Crypto::cryptoInfo() { cout << currency << " : " << exchangeRate << endl; }

//updating the rate
void Crypto::changeRate(double newRate)
{
    prevCourses.push_back(exchangeRate);
    exchangeRate = newRate;
}

/*
predicting a new course. It calculate an average difference of all courses and then 
it add it to the previous one
*/
double Crypto::prediction()
{
    if (prevCourses.size() < predictionAccuracy)
    {
        cout << "There is not enough data in the system! Next course cannot be predicted." << endl;
        return 0;
    }
    else
    {
        double avg = 0;
        for (int i = 0; i < predictionAccuracy; i++)
        {
            avg += prevCourses[prevCourses.size() - i - 1];
        }
        avg /= predictionAccuracy;
        return exchangeRate + (exchangeRate - avg);
    }
}

double Crypto::profitLoss(double amount){
    return amount * prediction();
} 

void Crypto::newTransaction(string mail, string type, double newAmount, double newCourse) {
    Transaction<string> trans(mail, type, newAmount, newCourse);
    transactionsCryptos.push_back(trans);
}
    
void Crypto::showTransactions(){
    for(int i = 0; i < transactionsCryptos.size();  i++){
        transactionsCryptos[i].transactionInfo();
    }
}