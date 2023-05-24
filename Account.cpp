#include "Account.hpp"

int Account::nextID = 0;

Account::Account(const int customerID) : customerID(customerID), accountID(nextID++){
	//Initialises an object with a customer ID and a unique account ID
}

int Account::getAccountID() const {
	//Returns this objects account ID
	return this->accountID;
}

int Account::getCustomerID() const {
	//Returns this objects customer ID
	return this->customerID;
}

Money Account::getBalance() const {
	//Returns this objects balance
	return this->balance;
}

Account::~Account() {
}

