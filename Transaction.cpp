#include <chrono>
#include<string>
#include<iostream>
#include<time.h>
using namespace std;
/*
class transaction saves information about transaction it contains date when it was made, 
*/
template<typename type>
class Transaction {
private:
    string date; //date of transaction
    type data; //who made transaction
    string typeOfTransaction; //if it was a sell or buy
    double amount;  //how much was bought or sold
    double course;  //what rate was it made  
public: 
    Transaction(){}
    
    Transaction(string newDate, type newData, string transaction, double newAmount, double newCourse):
    date(newDate), data(newData), typeOfTransaction(transaction), amount(newAmount), course(newCourse){}
    
    Transaction(type newData, string transaction, double newAmount, double newCourse):
    data(newData), typeOfTransaction(transaction), amount(newAmount), course(newCourse) {
       /*
               auto current_time = chrono::system_clock::now();
        time_t current_time_t = chrono::system_clock::to_time_t(current_time);
        time_t localTime;
        tm tm_obj;
        time(&localTime);
        struct tm* current_date = localtime_s(&localTime, &tm_obj);

        date = to_string(current_date->tm_year + 1900 ) + "-" + to_string( current_date -> tm_mon + 1 ) + "-" + to_string( current_date -> tm_mday );
    */
    }

    ~Transaction(){}

    string getDate(){
        return date;
    }

    type getData(){
        return data;
    }

    double getAmount(){
        return amount;
    }

    double getCourse(){
        return course;
    }
     
    string getType(){
        return typeOfTransaction;
    }

    //displaying info about transaction
    void transactionInfo(){
        cout << date << " " << data << " " << typeOfTransaction << ", amount : " << amount << " course: " << course <<endl ; 
    }

};
