##Features

###Class User:

**1.	User Data Management:**

-	Changing first name, last name, password (with validation).
-	Displaying user information.
  
**2.	Transactions:**
 	
-	Adding new transactions.
-	Displaying transaction history.
  
**3.	Cryptocurrency Trading:**

-	Buying and selling cryptocurrencies.
-	Tracking user balance in different cryptographic currencies.
-	Displaying information about owned cryptocurrencies.
  
**4.	Connection with the Bank class (bank account):**

-	Inheritance from the Bank class.
-	Displaying information about the user's account status.

###Class Bank (bank account):

The Bank class represents a user's bank account, capable of managing balances in a main currency and optional balances in various cryptocurrencies. It provides functionality for initializing account details, depositing and withdrawing money, and managing cryptocurrency balances.

**1.	Managing Account State:**

-	Deposits and withdrawals of funds. 
-	Tracking account balance in different currencies.
  
**2.	Cryptocurrency Handling:** 

-	Updating and displaying the account balance in cryptocurrencies.
  
**3.	Exception Handling:** 

-	Throwing an exception in case of insufficient funds during a withdrawal.
  
##Transaction Class: 

**1.	Transaction Recording:**

-	Creating transaction objects with information such as date, transaction participant, transaction type (buy/sell), quantity, and exchange rate. 
-	Displaying Transaction Information: 
-	Reviewing transaction history.
  
##Crypto Class:

The Crypto class represents a cryptocurrency within the trading platform. It encapsulates information such as the currency's name, exchange rate, transaction history, and past exchange rates. The class facilitates operations like changing the exchange rate, displaying information, calculating profit or loss, and managing transactions.

**1.	Cryptocurrency Handling: **

-	Creating cryptocurrency-related transactions. 
-	Updating cryptocurrency exchange rates.
-	Predicting next currency rate, and calculate a profit or loss of invested money by user.   

**2.	Recording and displaying information:**

-	Adding and displaying information about cryptocurrencies and trastactions.

##TradingPlatform class:

The TradingPlatform class acts as an intermediary between the main program and the functionalities of individual classes. It handles user registration, cryptocurrency management, and facilitates various transactions. The class is responsible for displaying messages, validating data (e.g., passwords or emails), and managing interactions between users and cryptocurrencies.

**1.	Displaying Data:**

-	Displaying available cryptocurrencies
-	Displaying registered users
-	Displaying information about user transactions or cryptocurrency transactions
-	Displaying data about account balance

**2.	Adding New Data:**

-	Adding new currency exchange rates
-	Adding new registered users
-	Adding new currency
-	Loading data about users or currencies from a file

**3.	Bank Operations:**

-	Buying and selling currency
-	Depositing or withdrawing money from the account
-	Predicting loss or profit

**4.	Saving Information:**

-	Saving information about registered users or cryptocurrencies in the system

##General Remarks: 

**1.	Security Measures:**

-	Security functions, such as password verification during user data changes, are implemented. 

**2.	Transaction History:**

-	The transaction system allows monitoring all user operations, including date, operation type, quantity, and exchange rate. 

**3.	Fund Management:**

-	Enabling users to manage their funds in both traditional currency and cryptocurrencies.

##Object-Oriented Approach:

**1.	Encapsulation**

- Private Data Members: 
The User class encapsulates private data members such as name, surname, address email password, age or made transactions. Data is hidden and accessed through member functions, ensuring data integrity and security.

**2.	Inheritance**

-	Account Hierarchy: 
The User class inherits from the Bank class because each user has their own bank account on which they can perform operations. This hierarchical structure allows for code reuse and extensibility."

**3.	Polymorphism** 

-	Polymorphism: 
Adding user method in TradingPlatform class. It allows to add users with different data.  

-	Overloading operators: 
Overloading operators + and - in the Bank class. This is a form of compile-time polymorphism. It allows for more convenient deposit and withdrawal operations from the account. 

**4.	Template class**

-	Template: The class Transaction is designed as a template, allowing it to work with different types of entities (e.g., string, int). For example if user would have another identifier. For example instead of email (String), id given by system.  

##User Interaction and Main Program:

-	Menu-Driven Interface: The application employs a menu-driven interface, allowing users to create, perform transactions, and view account information through a structured menu system.
-	Object Creation: Users have the capability to dynamically create objects of the Users and Cryptos classes, enabling the flexible instantiation of user and cryptocurrency entities.
-	Transaction Handling: The system adeptly manages diverse transactions, ensuring the validation of proper balance and security measures. Real-time updates are displayed to provide users with timely information on their transactions.

