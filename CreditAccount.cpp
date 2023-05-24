#include "CreditAccount.hpp"

CreditAccount::CreditAccount(const int customerID) : Account(customerID) {
	//Initialises the object with a given customer ID
}

bool CreditAccount::withdrawMoney(Money amount) {
	//balance can be negative but the amount passed into the function cannot be negative
	if (amount.asCents() >= 0) {
		balance.subtract(amount);
		//Return true of the withdrawal was successful
		return true;
	}
	//Return false of the withdrawal was unsuccessful
	return false;
}

bool CreditAccount::depositMoney(Money amount) {
	//the balance of this account can not exceed 5000 dollars so check for this
	if (amount.asCents() >= 0 && (balance.asCents() + amount.asCents()) <= 500000) {
		balance.add(amount);
		//Return true of the deposit was successful
		return true;
	}
	//Return false of the deposit was unsuccessful
	return false;
}

bool CreditAccount::testWithdraw(Money amount) {
	//Helper function used to check whether or not a withdrawal can be completed; true if successful, false if unsuccessful
	return true;
}

bool CreditAccount::testDeposit(Money amount) {
	//Helper function used to check whether or not a deposit can be completed; true if successful, false if unsuccessful
	if ((balance.asCents() + amount.asCents()) <= 500000) {
		return true;
	}
	return false;
}

CreditAccount::~CreditAccount() {
}
