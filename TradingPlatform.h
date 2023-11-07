#pragma once
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include "User.h"
#include "Crypto.h"

using namespace std;

class TradingPlatform
{
private:
    map<string, User> users;
    map<string, Crypto> cryptos;

public:
    TradingPlatform();
    ~TradingPlatform();
    void showUsers(); //Displaying all users 
    void showCryptos();
    void addUser(string name, string surname, string mail, string password, int age);
    void addUser(string name, string surname, string mail, string password, int age, int begBalance);
    void addUser(class User &us);
    void addUser(string name, string surname, string mail, string password, int age, int begBalance, vector<Transaction<string>> v);
    void addCrypto(string currency, double rate);
    void addCrypto(class Crypto &cr);
    void changeRate();
    void showUsersTransactions();
    void showCryptosTransactions();
    void buyCryptocurrency();
    void sellCryptocurrency();
    bool deposit();
    bool withdraw();
    void giveTotalEquity();
    void predictLossProfit();
    void readFileCryptos();
    void readFileUsers();
    void saveFileUsers();
    void saveFileCryptos();
    void changeUserData();
};
