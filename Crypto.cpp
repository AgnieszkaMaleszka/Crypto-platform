#include "Crypto.h"
using namespace std;

// required days to predict a course. 5 means that at least 5 rates are required to calculate predicted course.
int predictionAccuracy = 3;

Crypto::Crypto() : exchangeRate(0) {}

//constructor adding a currency with name and exchangeRate
Crypto::Crypto(string newCurrency, double newExchange) : currency(newCurrency), exchangeRate(newExchange) {}

//return previous courses
vector<double> Crypto::getPrevCourses() { return prevCourses; }

//adding a new transaction
void Crypto::addTransaction(Transaction<string> &trans) { transactionsCryptos.push_back(trans); }

//return a currency name
string Crypto::getCurrency() { return currency; }

//return previous rates
double Crypto::getExchangeRate() { return exchangeRate; }

//return transactions for cryptos, who bought certain currency
vector<Transaction<string>> Crypto::getTransactions() { return transactionsCryptos; }

//adding a new transaction
void Crypto::setTransactions(vector<Transaction<string>> newTransactions) { transactionsCryptos = newTransactions; }  

void Crypto::cryptoInfo() { cout << currency << " : " << exchangeRate << endl; }

//updating the rate
void Crypto::changeRate(double newRate)
{
    cout<<"ile kursow "<<prevCourses.size()<<endl;
    prevCourses.push_back(exchangeRate);
    exchangeRate = newRate;
}


//predicting a new course. It calculate an average difference of all courses and then it add it to the previous one
double Crypto::prediction()
{
    vector <double> courses = getPrevCourses();
    if (courses.size() < predictionAccuracy)
    {
        cout << "There is not enough data in the system! Next course cannot be predicted." << endl;
        cout<< "There is " << courses.size() <<" at least "<<predictionAccuracy<<" rates is required\n";
        return 0;
    }
    else
    {
        double avg = 0;
        for (int i = 0; i < predictionAccuracy; i++)
        {
            avg += courses[courses.size() - i - 1];
        }
        avg /= predictionAccuracy;
        return exchangeRate + (exchangeRate - avg);
    }
}

//user gives an amount of certain crypto and it returns how much he can earn or loss
double Crypto::profitLoss(double amount){
    return amount * prediction();
} 

void Crypto::newTransaction(string mail, string type, double newAmount, double newCourse) {
    Transaction<string> trans(mail, type, newAmount, newCourse);
    transactionsCryptos.push_back(trans);
}

//shows transactions made by user    
void Crypto::showTransactions(){
    for(int i = 0; i < transactionsCryptos.size();  i++){
        transactionsCryptos[i].transactionInfo();
    }
}