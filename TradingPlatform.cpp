#include "TradingPlatform.h"

/*
Trading Platform pośredniczy między główną częścią programu a funkcjonalnością poszczególnych klas. 
Wyświetla komunikaty oraz sprawdza poprawność danych np. hasła lub maila
*/
TradingPlatform::TradingPlatform() : users(), cryptos() {}

TradingPlatform::~TradingPlatform() {}

/*
Displaying a list of registed users. For each user it calls a function userInfo, which display all details about user, 
such as mail, name, surname, age or account balance.
*/
void TradingPlatform::showUsers() {
    std::cout << "List of registered users\n";
    for (const auto &entry : users) {
        std::string mail = entry.first;
        User us = entry.second;
        us.userInfo();
    }
}

/*
Displaying a list of avaliable cryptocurrency. For each currency it calls a function cryptoInfo, which display all details about it, 
such as name or actual rate.
*/
void TradingPlatform::showCryptos() {
    std::cout << "List of available cryptos\n";
    for (const auto &entry : cryptos) {
        std::string ID = entry.first;
        Crypto cs = entry.second;
        cs.cryptoInfo();
    }
}

/*
addUser - adding a new user to data base
*/
void TradingPlatform::addUser(std::string name, std::string surname, std::string mail, std::string password, int age) {
    if (users.find(mail) != users.end()) {
        std::cout << "This e-mail is already registered!\n";
    } else {
        User newUser(name, surname, mail, password, age);
        users[newUser.getMail()] = newUser;
        std::cout << "New user was successfully added\n";
    }
}

void TradingPlatform::addUser(std::string name, std::string surname, std::string mail, std::string password, int age, int begBalance) {
    if (users.find(mail) != users.end()) {
        std::cout << "This e-mail is already registered!\n";
    } else {
        User newUser(name, surname, mail, password, age, begBalance);
        users[newUser.getMail()] = newUser;
        std::cout << "New user was successfully added\n";
    }
}

void TradingPlatform::addUser(User &us) {
    if (users.find(us.getMail()) != users.end()) {
        // User with this email already exists
    } else {
        users[us.getMail()] = us;
        std::cout << "New user was successfully added\n";
    }
}

void TradingPlatform::addUser(std::string name, std::string surname, std::string mail, std::string password, int age, int begBalance, std::vector<Transaction<std::string>> v) {
    if (users.find(mail) != users.end()) {
        std::cout << "This e-mail is already registered!\n";
    } else {
        User newUser(name, surname, mail, password, age, begBalance, v);
        users[newUser.getMail()] = newUser;
        std::cout << "New user was successfully added\n";
    }
}
/*
addCrypto - adding new cryptocurrency to data base
*/
void TradingPlatform::addCrypto(std::string currency, double rate) {
    if (cryptos.find(currency) != cryptos.end()) {
        std::cout << "This cryptocurrency is already registered!\n";
    } else {
        Crypto newCrypto(currency, rate);
        cryptos[currency] = newCrypto;
        std::cout << "New crypto was successfully added\n";
    }
}

void TradingPlatform::addCrypto(Crypto &cr) {
    if (cryptos.find(cr.getCurrency()) != cryptos.end()) {
        // Crypto with this currency already exists
    } else {
        cryptos[cr.getCurrency()] = cr;
        std::cout << "New crypto was successfully added\n";
    }
}

/*
changeRate - allows user to change rate of cryptocurrency, the previous rate is  saved to predict new course in future
*/
void TradingPlatform::changeRate() {
    double newRate;
    std::string currency;

    std::cout << "Enter a currency which Rate you want to change\n";
    std::cin >> currency;
    std::cout << std::endl;

    std::cout << "Enter new Rate: ";
    std::cin >> newRate;
    std::cout << std::endl;

    if (cryptos.find(currency) == cryptos.end()) {
        std::cout << "This currency was not found. \n";
    } else {
        cryptos[currency].changeRate(newRate);
    }
}

/*
displaying user transaction, what currency he bought or sold and for what rate
*/
void TradingPlatform::showUsersTransactions() {
    std::string mail;
    std::cout << "Enter address e-mail: ";
    std::cin >> mail;
    std::cout << std::endl;

    if (users.find(mail) == users.end()) {
        std::cout << "This user was not found. \n";
    } else {
        std::cout << "Transactions for user " << mail << ": \n";
        users[mail].showTransactions();
    }
}

/*
displaying cryptocurrency transaction, if it was sold/bought by who for which rate 
*/
void TradingPlatform::showCryptosTransactions() {
    std::string currency;
    std::cout << "Enter currency: ";
    std::cin >> currency;
    std::cout << std::endl;

    if (cryptos.find(currency) == cryptos.end()) {
        std::cout << "This cryptocurrency was not found. \n";
    } else {
        std::cout << "Transactions for " << currency << ": \n";
        cryptos[currency].showTransactions();
    }
}

/*
buying a cryptocurrency and display an account balance of user 
*/
void TradingPlatform::buyCryptocurrency() {
    std::string mail;
    double amount;
    std::string password, currency;

    std::cout << "Enter address e-mail: ";
    std::cin >> mail;
    std::cout << std::endl;

    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cout << std::endl;

    std::cout << "Enter currency: ";
    std::cin >> currency;
    std::cout << std::endl;

    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << std::endl;

    if (cryptos.find(currency) == cryptos.end()) {
        std::cout << "This cryptocurrency was not found. \n";
    } else {
        if (password == users[mail].getPassword()) {
            users[mail].buyCrypto(amount, cryptos[currency], users[mail]);
            std::cout << "Your account balance: " << users[mail].getBalance() << users[mail].getAccountCurrency() << std::endl;
        }
    }
}

/*
sell a cryptocurrency and display an account balance of user 
*/
void TradingPlatform::sellCryptocurrency() {
    std::string mail;
    double amount;
    std::string password, currency;

    std::cout << "Enter address email: ";
    std::cin >> mail;
    std::cout << std::endl;

    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cout << std::endl;

    std::cout << "Enter currency: ";
    std::cin >> currency;
    std::cout << std::endl;

    std::cout << "Enter password:";
    std::cin >> password;
    std::cout << std::endl;

    if (cryptos.find(currency) == cryptos.end()) {
        std::cout << "This cryptocurrency was not found \n";
    } else {
        if (password == users[mail].getPassword()) {
            users[mail].sellCrypto(amount, cryptos[currency], users[mail]);
            std::cout << "Your account balance: " << users[mail].getBalance() << users[mail].getAccountCurrency() << std::endl;
        }
    }
}

/*
user can deposit money, it is add to his bank account
*/
bool TradingPlatform::deposit() {
    std::string mail;
    double amount;
    std::string password;

    std::cout << "Enter address e-mail: ";
    std::cin >> mail;
    std::cout << std::endl;

    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cout << std::endl;

    std::cout << "Enter password:";
    std::cin >> password;
    std::cout << std::endl;

    if (users.find(mail) == users.end()) {
        std::cout << "This user does not exist!\n";
        return false;
    } else {
        try {
            if (password == users[mail].getPassword()) {
                users[mail] + amount;
                std::cout << "Money was successfully deposited.\n";
                std::cout << "Your account balance: " << users[mail].getBalance() << users[mail].getAccountCurrency() << std::endl;
                return true;
            } else {
                std::cout << "Wrong password!\n";
                return false;
            }
        } catch (const char *msg) {
            std::cout << "Error. There is not enough money in the account.\n";
            return false;
        }
    }
}

/*
user can withdraw money it is subtract from his bank account, also it is checked whether he has enough cash 
*/
bool TradingPlatform::withdraw() {
    std::string mail;
    double amount;
    std::string password;

    std::cout << "Enter address e-mail: ";
    std::cin >> mail;
    std::cout << std::endl;

    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cout << std::endl;

    std::cout << "Enter password:";
    std::cin >> password;
    std::cout << std::endl;

    if (users.find(mail) == users.end()) {
        std::cout << "This user does not exist!\n";
        return false;
    } else {
        try {
            if (password == users[mail].getPassword()) {
                users[mail] - amount;
                std::cout << "Money was successfully withdrawn.\n";
                std::cout << "Your account balance: " << users[mail].getBalance() << users[mail].getAccountCurrency() << std::endl;
                return true;
            } else {
                std::cout << "Wrong password!\n";
                return false;
            }
        } catch (const char *msg) {
            std::cout << "Error. There is not enough money in the account.\n";
            return false;
        }
    }
}

/*
calculate total accpint ballance with added all cryptocurrencies with present rate 
*/
void TradingPlatform::giveTotalEquity() {
    std::string mail;
    std::string password;

    std::cout << "Enter address e-mail: ";
    std::cin >> mail;
    std::cout << std::endl;

    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << std::endl;

    if (users.find(mail) == users.end()) {
        std::cout << "User with this ID was not found. \n";
    } else if (password == users[mail].getPassword()) {
        std::cout << "Total equity for user " << mail << users[mail].totalEquity();
    } else {
        std::cout << "Wrong password!\n";
    }
}

/*
predict loss or earn money when you sell the cryptocurrency, it is calculated by previous courses 
*/
void TradingPlatform::predictLossProfit() {
    std::string currency;
    double amount;

    std::cout << "Enter currency: ";
    std::cin >> currency;
    std::cout << std::endl;

    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cout << std::endl;

    double predictions;
    if (cryptos.find(currency) == cryptos.end()) {
        std::cout << "This cryptocurrency was not found \n";
    } else {
        predictions = cryptos[currency].profitLoss(amount);
        if (predictions > 0) {
            std::cout << "Predicted profit: " << predictions << std::endl;
        } else if (predictions < 0) {
            std::cout << "Predicted loss: " << predictions << std::endl;
        } else {
            std::cout << "No loss and no profit is predicted \n";
        }
    }
}

/*
load data about crypto currencies from file 
*/
void TradingPlatform::readFileCryptos() {
    std::ifstream file("cryptos.txt");
    if (!file.is_open()) {
        std::cout << "File cryptos.txt does not exist in folder TradeCrypto\\files" << std::endl;
        return;
    }

    std::string currency;
    double rate;
    std::vector<Crypto> cryptos;
    std::string label;
    std::vector<double> Rates;
    std::vector<Transaction<std::string>> transactions;
    std::string Date, Data, Type;
    double Amount, course;

    while (file >> label) {
        if (label == "CRYPTO:") {
            file >> currency >> rate;
            Crypto newCrypto(currency, rate);
            cryptos.push_back(newCrypto);
        } else if (label == "TRANSACTIONS:") {
            file >> Date >> Data >> Type >> Amount >> course;
            Transaction<std::string> trans(Date, Data, Type, Amount, course);
            cryptos[cryptos.size() - 1].addTransaction(trans);
        } else if (label == "EXCHANGE_RATE:") {
            file >> course;
            Rates.push_back(course);
        }
    }

    for (int i = 0; i < cryptos.size(); i++) {
        addCrypto(cryptos[i]);
    }

    file.close();
    std::cout << "Cryptocurrency transactions and exchange rates were successfully imported." << std::endl;
}

/*
load data about users from file 
*/
void TradingPlatform::readFileUsers() {
    std::ifstream file("users.txt");
    if (!file.is_open()) {
        std::cout << "File users.txt does not exist in folder TradeCrypto\\files" << std::endl;
        return;
    }

    std::string name, surname, mail, password;
    int age;
    double balance;
    std::vector<User> users;
    std::string label;
    std::vector<Transaction<std::string>> transactions;
    std::string Date, Data, Type, currency;
    double Amount, course;
    bool check = false;

    while (file >> label) {
        if (label == "USER:") {
            file >> name >> surname >> mail >> password >> age >> balance;
            User newUser(name, surname, mail, password, age, balance);
            users.push_back(newUser);
            check = true;
        } else if (label == "TRANSACTIONS:") {
            file >> Date >> Data >> Type >> Amount >> course;
            Transaction<std::string> trans(Date, Data, Type, Amount, course);
            users[users.size() - 1].addTransaction(trans);
        } else if (label == "BANK:") {
            file >> currency >> Amount;
            users[users.size() - 1].updateCryptoBalance(currency, Amount);
        }
    }

    for (int i = 0; i < users.size(); i++) {
        addUser(users[i]);
    }

    file.close();
    std::cout << "Users and transactions were successfully imported." << std::endl;
}

/*
upload data about users to file
*/
void TradingPlatform::saveFileUsers() {
    std::ofstream file;
    file.open("users.txt"); // Fixed path
    file << std::endl;
    if (!file.good()) {
        std::cout << "File users.txt does not exist in folder TradeCrypto\\files" << std::endl;
        return;
    } else {
        for (const auto &entry : users) {
            std::string mail = entry.first;
            User us = entry.second;
            file << "USER: ";
            file << us.getName() << " " << us.getSurname() << " " << us.getMail() << " " << us.getPassword() << " " << us.getAge() << " " << us.getBalance() << std::endl;

            // Save the last 10 transactions
            std::vector<Transaction<std::string>> transactions = us.getTransactions();
            int numTransactionsToSave = std::min(10, static_cast<int>(transactions.size()));
            for (int i = transactions.size() - numTransactionsToSave; i < transactions.size(); i++) {
                file << "TRANSACTIONS: " << transactions[i].getDate() << " " << transactions[i].getData() << " " << transactions[i].getType() << " " << transactions[i].getAmount() << " " << transactions[i].getCourse() << std::endl;
            }

            std::map<std::string, double> mp = us.getCryptoBalances();
            for (const auto &entry : mp) {
                file << "BANK: " << entry.first << " " << entry.second << std::endl;
            }
        }
    }
    std::cout << "User data was successfully saved." << std::endl;
}

/*
upload data about cryptocurrency to file
*/
void TradingPlatform::saveFileCryptos() {
    std::ofstream file;
    file.open("cryptos.txt"); // Fixed path
    file << std::endl;
    if (!file.good()) {
        std::cout << "File cryptos.txt does not exist in folder TradeCrypto\\files" << std::endl;
        return;
    } else {
        for (const auto &entry : cryptos) {
            std::string currency = entry.first;
            Crypto cr = entry.second;
            file << "CRYPTO: " << cr.getCurrency() << " " << cr.getExchangeRate() << std::endl;

            // Save the last 10 transactions
            std::vector<Transaction<std::string>> transactions = cr.getTransactions();
            int numTransactionsToSave = std::min(10, static_cast<int>(transactions.size()));
            for (int i = transactions.size() - numTransactionsToSave; i < transactions.size(); i++) {
                file << "TRANSACTIONS: " << transactions[i].getDate() << " " << transactions[i].getData() << " " << transactions[i].getType() << " " << transactions[i].getAmount() << " " << transactions[i].getCourse() << std::endl;
            }

            std::vector<double> rates = cr.getPrevCourses();
            for (int i = 0; i < rates.size(); i++) {
                file << "EXCHANGE_RATE: " << rates[i] << std::endl;
            }
        }
    }
    std::cout << "Cryptocurrency data was successfully saved." << std::endl;
}

/*
changing user informations
*/
void TradingPlatform::changeUserData(){
        string mail, password;
        cout << "Enter address e-mail: ";
        cin >> mail;
        cout << endl;
        
        cout << "Enter password: ";
        cin >> password;
        cout << endl;

        if (users.find(mail) == users.end()) {
            cout << "User with this adress e-mail was not found. \n";
        }else if(password == users[mail].getPassword()) users[mail].changeData(password);
            else cout << "Wrong passowrd!\n";
    }