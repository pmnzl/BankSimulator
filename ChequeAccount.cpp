#include "ChequeAccount.hpp"

ChequeAccount::ChequeAccount(const int customerID) : Account(customerID) {
	//Initialises an object with a specified customer ID and a transaction fee starting at 1 dollar
	transaction_fee.addDollars(1);
}

bool ChequeAccount::withdrawMoney(Money amount) {
	//Only amounts of zero or more may be withdrawn from the account
	//Checking if withdrawing a specified amount will put the account into a negative balance
	if (balance.asCents() >= (amount.asCents() + transaction_fee.asCents()) && amount.asCents() >= 0) {
		//Subtracts desired amount from account plus a transaction fee
		balance.subtract(amount);
		balance.subtract(transaction_fee);
		transaction_fee.addDollars(1);		//Transaction fee also increases due to transaction
		//Return true of the withdrawal was successful
		return true;
	}
	//Return false of the withdrawal was unsuccessful
	return false;
}

bool ChequeAccount::depositMoney(Money amount) {
	//Only amounts of zero or more may be deposited from the account
	//Amount deposited can not be more than 3000 dollars
	if (amount.asCents() <= 300000 && amount.asCents() >= 0) {
		balance.add(amount);
		//Return true of the deposit was successful
		return true;
	}
	//Return false of the deposit was unsuccessful
	return false;
}

Money* ChequeAccount::getTransactionFee() const {
	//Returns this objects transaction fee value
	return trans;
}

bool ChequeAccount::testWithdraw(Money amount) {
	//Helper function used to check whether or not a withdrawal can be completed; true if successful, false if unsuccessful
	if (balance.asCents() >= (amount.asCents() + transaction_fee.asCents())) {
		return true;
	}
	return false;
}

bool ChequeAccount::testDeposit(Money amount) {
	//Helper function used to check whether or not a deposit can be completed; true if successful, false if unsuccessful
	if (amount.asCents() <= 300000) {
		return true;
	}
	return false;
}

ChequeAccount::~ChequeAccount() {
}

