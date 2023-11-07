#pragma once
#include<vector>
#include "Bank.h"
#include "Transaction.h"
#include "Crypto.h"
using namespace std;

class User : public Bank
{
private:
    string name;
    string surname;
    string mail;
    string password;
    int age;
    vector<Transaction<string>> transactions;

public:
    User();
    User(string newName, string newSurname, string newMail, string newPassword, int newAge);
    User(string newName, string newSurname, string newMail, string newPassword, int newAge, int balance);
    User(string newName, string newSurname, string newMail, string newPassword, int newAge, int balance, vector<Transaction<string>> v);
    User(string newName, string newSurname, string newMail, string newPassword, int newAge, int balance, const map<string, double> &initialCryptoBalances);
    ~User();

    vector<Transaction<string>> &getTransactions();
    string getName();
    string getSurname();
    string getMail();
    string getPassword();
    int getAge();

    void addTransaction(Transaction<string> &trans);
    void changeData(string pass);
    vector<Transaction<string>> newTransaction(string newCurrency, string type, double newAmount, double newCourse);
    void showTransactions();
    void userInfoDev();
    void userInfo();
    void buyCrypto(double amount, Crypto &cryptoName, User username);
    void sellCrypto(double amount, Crypto &cryptoName, User username);
    double totalEquity();
    void setTransactions(vector<Transaction<string>> v);
};
