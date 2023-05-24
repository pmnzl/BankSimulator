#include "Transaction.hpp"
#include <string>

//Initialise static variable
int Transaction::nextID = 1;

Transaction::Transaction(Account* fromAccount, Account* toAccount, Money amount)
	: state(PENDING), transactionID(nextID++), amount(amount), Acc_1_Location(fromAccount), Acc_2_Location(toAccount) {
	//Initialising the transaction class with its variables and checking if the amount used for the transaction is more than zero
	//if not the amount is changed to zero
	if (amount.asCents() < 0) {
		this->amount = Money(0, 0);
	}
}

bool Transaction::performTransaction() {
	//Using helper functions from the account class to determine whether a transaction will be successful without actually
	//executing the transaction
	bool trans_1 = Acc_1_Location->testWithdraw(this->amount);
	bool trans_2 = Acc_2_Location->testDeposit(this->amount);

	//If transaction is possible execute the transaction and mark it as COMPLETED an returns true
	if (trans_1 == true && trans_2 == true) {
		Acc_1_Location->withdrawMoney(this->amount);
		Acc_2_Location->depositMoney(this->amount);
		this->state = COMPLETED;
		return true;
	}
	//If the transaction is not possible mark the transaction as FAILED and returns false
	this->state = FAILED;
	return false;
}

TransactionState Transaction::getState() const {
	//Gets this objects transaction state
	return this->state;
}

Money Transaction::getAmount() const {
	//Gets this objects transaction amount
	return this->amount;
}

Account* Transaction::getToAccount() const {
	//Get this objects deposit account
	return this->Acc_2_Location;
}

Account* Transaction::getFromAccount() const {
	//Get this objects withdrawal account
	return this->Acc_1_Location;
}

int Transaction::getID() const {
	//Gets the transaction ID of this objects transaction
	return this->transactionID;
}

Transaction::~Transaction() {
}

