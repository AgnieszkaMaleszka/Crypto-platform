#include "TradingPlatform.h"
#include <iostream>
using namespace std;
/*
    Options:
    1 - showUsers
    2 - showCryptos
    3 - addUser
    4 - addCrypto
    5 - showUsersTransactions(ID)
    6 - showCryptosTransactions(currency)
    7 - buyCryptocurrency
    8 - sellCryptocurrency
    9 - deposit
    10 - withdraw
    11 - findID
    12 - predictLossProfit
    13 - readFileUsers
    14 - readFileCryptos
    15 - saveFileUsers
    16 - saveFileCryptos
    17 - changeRate
    18 - change user account data  
    0 - end
*/
int main()
{
    TradingPlatform platform;
    int operations;
    bool test = true, test2 = false;
    while (test)
    {
        cout << "Options:" << endl;
        cout << "1 - showUsers" << endl;
        cout << "2 - showCryptos" << endl;
        cout << "3 - addUser" << endl;
        cout << "4 - addCrypto" << endl;
        cout << "5 - showUsersTransactions(ID)" << endl;
        cout << "6 - showCryptosTransactions(currency)" << endl;
        cout << "7 - buyCryptocurrency" << endl;
        cout << "8 - sellCryptocurrency" << endl;
        cout << "9 - deposit" << endl;
        cout << "10 - withdraw" << endl;
        cout << "11 - findID" << endl;
        cout << "12 - predictLossProfit" << endl;
        cout << "13 - readFileUsers" << endl;
        cout << "14 - readFileCryptos" << endl;
        cout << "15 - saveFileUsers" << endl;
        cout << "16 - saveFileCryptos" << endl;
        cout << "17 - changeRate" << endl;
        cout << "18 - change user account data" << endl;
        cout << "0 - end" << endl;
        cin >> operations;
        switch (operations)
        {
        case 1:
            platform.showUsers();
            break;
        case 2:
            platform.showCryptos();
            break;
        case 3:
        {
            string name;
            string surname;
            string mail;
            string password;
            int age;

            cout << "Enter name: ";
            cin >> name;
            cout << endl;

            cout << "Enter surname: ";
            cin >> surname;
            cout << endl;

            cout << "Enter mail: ";
            cin >> mail;
            cout << endl;

            cout << "Enter password: ";
            cin >> password;
            cout << endl;

            cout << "Enter age: ";
            cin >> age;
            cout << endl;

            platform.addUser(name, surname, mail, password, age, 0);
            break;
        }
        case 4:
        {
            string currency;
            double exchangeRate;
            cout << "Enter currency: ";
            cin >> currency;
            cout << endl;

            cout << "Enter exchangeRate: ";
            cin >> exchangeRate;
            cout << endl;
            platform.addCrypto(currency, exchangeRate);
            break;
        }
        case 5:
            platform.showUsersTransactions();
            break;
        case 6:
            platform.showCryptosTransactions();
            break;
        case 7:
            platform.buyCryptocurrency();
            break;
        case 8:
            platform.sellCryptocurrency();
            break;
        case 9:
            platform.deposit();
            break;
        case 10:
            platform.withdraw();
            break;
        case 11:
            platform.giveTotalEquity();
            break;
        case 12:
            platform.predictLossProfit();
            break;
        case 13:
            platform.readFileUsers();
            break;
        case 14:
            platform.readFileCryptos();
            break;
        case 15:
            platform.saveFileUsers();
            break;
        case 16:
            platform.saveFileCryptos();
            break;
        case 17:
            platform.changeRate();
            break;
        case 18:
            platform.changeUserData();
            break; 
        case 0:
            if (test)
            {
                int saveChoice;
                cout << "Do you want to save changes? (Yes - type 1) \n";
                cin >> saveChoice;
                if (saveChoice == 1)
                {
                    platform.saveFileUsers();
                    platform.saveFileCryptos();
                }
                cout << "End of program.";
                test = false;
            }
            break;
        default:
            cout << "Wrong type of operation!\n";
            break;
        }
    }
    return 0;
}
