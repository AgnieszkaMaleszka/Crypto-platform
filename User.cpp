
#include "User.h"

using namespace std;
/*
User class:
string Name: name of user
string Surname: surname of user
string Mail: unique for each user, it enable identification of user
string Password: it is requaired to confirm bank operations like withdraw, deposit etc. Or to change data
int Age: age of user
vector transactions:  contain user transaction
*/

// Inheritene of Bank

User::User() : Bank(0, "$"), transactions() {}

User::User(string newName, string newSurname, string newMail, string newPassword, int newAge)
    : name(newName), surname(newSurname), mail(newMail), password(newPassword), age(newAge), Bank(0, "$"), transactions() {}

User::User(string newName, string newSurname, string newMail, string newPassword, int newAge, int balance, vector<Transaction<string>> v)
    : name(newName), surname(newSurname), mail(newMail), password(newPassword), age(newAge), Bank(balance, "$"), transactions(v) {}

User::User(string newName, string newSurname, string newMail, string newPassword, int newAge, int balance)
    : name(newName), surname(newSurname), mail(newMail), password(newPassword), age(newAge), Bank(balance, "$"), transactions() {}

User::User(string newName, string newSurname, string newMail, string newPassword, int newAge, int balance, const map<string, double> &initialCryptoBalances)
    : name(newName), surname(newSurname), mail(newMail), password(newPassword), age(newAge), Bank(balance, "$", initialCryptoBalances), transactions() {}

User::~User() {}

//return user inforkmations 
vector<Transaction<string>> &User::getTransactions() { return transactions; }

string User::getName() { return name; }

string User::getSurname() { return surname; }

string User::getMail() { return mail; }

string User::getPassword() { return password; }

int User::getAge() { return age; }

void User::addTransaction(Transaction<string> &trans) { transactions.push_back(trans); }

//changing data of usser, it requaires to confirm by password, only main mail cannot be changed 
void User::changeData(string pass)
{
    if (pass == password)
    {
        string data;
        char ch;
        string newData, newData2;
        bool check = false;

        cout << "Input the data you want to change (name, surname, password): ";
        cin >> data;
        cin.ignore();

        if (data == "name" || data == "surname" || data == "password")
        {
            do
            {
                cout << "Give the new " << data << ": ";
                getline(cin, newData);

                if (newData.empty())
                {
                    cout << data << " cannot be empty. " << data << " change was canceled." << endl;
                }
                else
                {
                    cout << "Repeat the new " << data << ": ";
                    getline(cin, newData2);

                    if (newData != newData2)
                    {
                        cout << "Inputted data are different." << endl;
                        cout << "If you want to cancel changes, input 'X': ";
                        ch = getchar();

                        if (ch == 'X')
                        {
                            cout << "Changes was canceled! ";
                            break;
                        }
                    }
                    else
                    {
                        cout << "If you want to save changes, input 'S', if you want to cancel changes, input 'X': ";
                        ch = getchar();

                        if (ch == 'S')
                        {
                            if (data == "name")
                            {
                                name = newData;
                            }
                            else if (data == "surname")
                            {
                                surname = newData;
                            }
                            else if (data == "password")
                            {
                                password = newData;
                            }
                            cout << data << " was successfully changed!" << endl;
                        }
                        else if (ch == 'X')
                        {
                            cout << data << " change was canceled." << endl;
                        }
                    }
                }
            } while (ch != 'S' && ch != 'X');
        }
        else
        {
            cout << "Invalid data choice." << endl;
        }
    }
    else
    {
        cout << "Invalid password!" << endl;
    }
}

//adding a new transaction
vector<Transaction<string>> User::newTransaction(string newCurrency, string type, double newAmount, double newCourse)
{
    Transaction<string> trans(newCurrency, type, newAmount, newCourse);
    transactions.push_back(trans); 
    return transactions;
}
//shows what transactions user made, what currencies he bought or sold     
void User::showTransactions()
{
    for (auto transaction : transactions)
    {
        transaction.transactionInfo();
    }
}

//displaying all ifnormations about use
void User::userInfoDev()
{
    cout << "User name: " << name << endl;
    cout << "User surname: " << surname << endl;
    cout << "User e-mail: " << mail << endl;
    cout << "User password: " << password << endl;
    cout << "User age: " << age << endl;
    cout << "User balance: " << balance << endl;
}

void User::userInfo()
{
    cout << "Name: " << name << " Surname: " << surname << " e-mail: " << mail << " Age: " << age << " Balance: " << balance << endl;
    for (auto cryptoBalance : cryptoBalances)
    {
        cout << "Crypto: " << cryptoBalance.first << " Balance: " << cryptoBalance.second << endl;
    }
}

//buying currency by user 
void User::buyCrypto(double amount, Crypto &cryptoName, User username)
{
    double cost = amount * cryptoName.getExchangeRate();
    if (cost > balance)
        cout << "There is not enough money in the account.\n";
    else
    {
        if (cryptoBalances.find(cryptoName.getCurrency()) == cryptoBalances.end())
        {
            cryptoBalances[cryptoName.getCurrency()] = 0.0; /// If new cryotocurrency was bought then add it 
        }
        balance -= cost;
        cryptoBalances[cryptoName.getCurrency()] += amount;

        //saving a transaction for user
        transactions = username.newTransaction(cryptoName.getCurrency(), "buy", amount, cryptoName.getExchangeRate()); 
        //saving a transaction for currency
        cryptoName.newTransaction(username.getMail(), "buy", amount, cryptoName.getExchangeRate()); 
            cout << currency << " was successfully bought.\n";
    }
}
//selling currency by user 
void User::sellCrypto(double amount, Crypto &cryptoName, User username)
{
    double cost = amount * (1 / cryptoName.getExchangeRate()); // 1/Rate
    if (amount > cryptoBalances[cryptoName.getCurrency()])
        cout << "There is not enough money in the account.\n";
    else
    {
        if (cryptoBalances.find(cryptoName.getCurrency()) == cryptoBalances.end())
        {
            cout <<"This cryptocurrency does not exist. \n";
        }else {
            balance += cost;
            cryptoBalances[cryptoName.getCurrency()] -= amount;

            //saving a transaction for user
            transactions = username.newTransaction(cryptoName.getCurrency(), "sell", amount, (1 / cryptoName.getExchangeRate()));
            //saving a transaction for currency
            cryptoName.newTransaction(username.getMail(), "sell", amount, cryptoName.getExchangeRate());

            cout << currency << " was successfully sold.\n";
        }
    }
}

//calculate total account balance, adding a currency rates 
double User::totalEquity(){
        string nm;
        double bal;
        Crypto cur;
        for(const auto &entry : cryptoBalances){
            nm = entry.first;
            bal = entry.second;
            balance += cur.getExchangeRate() * bal;
        }
        return balance;
}