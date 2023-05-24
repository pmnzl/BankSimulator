#include "FinancialServicesSystem.hpp"
#include <vector>
#include <algorithm>

bool byID(const Transaction* l, const Transaction* r) {
	//Helper function used for the vector sort function to sort the object vector in ascending order by transaction ID
	return (l->getID() < r->getID());
}

FinancialServicesSystem::FinancialServicesSystem() {
}

std::string FinancialServicesSystem::author(){
	//Gives the author of the system
	return "";
}

bool FinancialServicesSystem::addCustomer(Customer* customer) {
	//Adds a customer to the system if they aren't already on the system
	//Returns true if the customer was successfully added to the customer vector
	//Returns false if the customer was not added to the customer vector

	//Check if there is an ID duplicate in the customer vector
	//If not add to the customer vector
	if (verifyCustomer(customer->getID()) == false) {
		this->customer.push_back(customer);
		return true;
	}

	return false;
}

bool FinancialServicesSystem::addAccount(Account* account) {
	//Adds an account to the system if it doesn't already exist
	//Returns true if the account was successfully added to the account vector
	//Returns false if the account was not added to the account vector

	if (verifyAccount(account->getAccountID()) == false && verifyCustomer(account->getCustomerID()) == true) {
		//Checks if the account ID already is in the account vector
		//If not, check if the customer ID exists in the customer vector
		//If it does add the account to the account vector and return true
		this->account.push_back(account);
		return true;
	}

	return false;
}

bool FinancialServicesSystem::addTransaction(Transaction* transaction) {
	//Adds a transaction (between two accounts with a transaction value) to the system

	//Check if the transaction already exists in the system, if true don't add another instance
	//Checking that both accounts in the transaction exist already in the system otherwise the transaction will fail
	//If these conditions are met then add the transaction to the transaction vector and return true, otherwise return false
	if (verifyTransaction(transaction->getID()) == false && transaction->getState() == PENDING &&
			verifyAccount(transaction->getToAccount()->getAccountID()) == true &&
				verifyAccount(transaction->getFromAccount()->getAccountID()) == true) {

		this->transaction.push_back(transaction);
		return true;
	}

	return false;
}

std::vector<Transaction*> FinancialServicesSystem::performPendingTransactions() {
	//Performs all pending transactions in order via uniqueID
	//Update status to COMPLETE if successful and return true or to FAILED if unsuccessful and return false
	//Successful transactions are added to a vector to return

	//Get a sorted vector of PENDING transactions to be completed and an empty vector to receive successful transactions
	std::vector<Transaction*> pending_transactions = getTransactions(PENDING);
	std::vector<Transaction*> successful_transactions;

	//Go through the pending transactions and perform them, if they are successful add them
	for (unsigned i = 0; i < pending_transactions.size(); i++) {
		if (pending_transactions[i]->performTransaction() == true) {
			successful_transactions.push_back(pending_transactions[i]);
		}
	}

	//Return the vector of successful transactions
	return successful_transactions;
}

Money FinancialServicesSystem::getCustomerBalance(int customerID) const {
	//Gets the balance of a customer over all their accounts

	//Temporary money object to sum all account values
	Money all_balance(0, 0);
	//Searches account vector for the specified customer ID and sums all the account values
	for (unsigned i = 0; i < this->account.size(); i++) {
		if (customerID == this->account[i]->getCustomerID()) {

			//Need to check if an account balance is negative as the Money class does not add or
			//subtract negative money values
			if (this->account[i]->getBalance().asCents() >= 0) {
				all_balance.addCents(this->account[i]->getBalance().asCents());
			}
			else {
				//Converts account balance to a positive to allow it to work with the money class
				all_balance.subtractCents(this->account[i]->getBalance().asCents()*-1);
			}
		}
	}

	//Returns the sum of all these accounts
	return all_balance;
}

bool FinancialServicesSystem::verifyCustomer(int customerID) const {
	//Checks the customer vector for an existing customer ID and returns true if detected and false if undetected
	for (unsigned int i = 0; i < this->customer.size(); i++) {
		if (customerID == this->customer[i]->getID()) {
			return true;
		}
	}
	return false;
}

bool FinancialServicesSystem::verifyAccount(int accountID) const {
	//Checks the account vector for an existing account ID and returns true if detected and false if undetected
	for (unsigned int i = 0; i < this->account.size(); i++) {
		if (accountID == this->account[i]->getAccountID()) {
			return true;
		}
	}
	return false;
}

bool FinancialServicesSystem::verifyTransaction(int transactionID) const {
	//Checks the transaction vector for an existing transaction ID and returns true if detected and false if undetected
	for (unsigned int i = 0; i < this->transaction.size(); i++) {
		if (transactionID == this->transaction[i]->getID()) {
			return true;
		}
	}
	return false;
}

std::vector<Account*> FinancialServicesSystem::getAccounts() const {
	//Returns this objects account vector
	return this->account;
}

std::vector<Customer*> FinancialServicesSystem::getCustomers() const {
	//Returns this objects customer vector
	return this->customer;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions() const {
	//Returns this objects transaction vector
	return this->transaction;
}

std::vector<Transaction*> FinancialServicesSystem::getTransactions(TransactionState state) const {
	//Gets a vector of transactions of a given state

	//Initialise a vector to store transactions of a given state
	std::vector<Transaction*> select_transactions;
	//Check transactions vector for transactions of a specific state and add them to a different vector
	for (unsigned int i = 0; i < this->transaction.size(); i++) {
		if (this->transaction[i]->getState() == state) {
			select_transactions.push_back(this->transaction[i]);
		}
	}

	//orders the vector with respect to the transaction IDs
	sort(select_transactions.begin(), select_transactions.end(), byID);

	//Returns a sorted transaction vector of a given state
	return select_transactions;
}

FinancialServicesSystem::~FinancialServicesSystem() {
}
