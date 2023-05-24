#include "SavingsAccount.hpp"

SavingsAccount::SavingsAccount(const int customerID) : Account(customerID) {
	//Initialise the object with a provided customer ID and a bonus starting at 10 dollars
	this->bonus.addDollars(10);
}

bool SavingsAccount::withdrawMoney(Money amount) {
	//Only amounts of zero or more may be withdrawn from the account
	//Checking if withdrawing a specified amount will put the account into a negative balance
	if (balance.asCents() >= amount.asCents() && amount.asCents() >= 0) {
		balance.subtract(amount);
		bonus.subtractDollars(2);
		if (bonus.asCents() < 0) {
			bonus = Money(0, 0);
		}
		//Return true of the withdrawal was successful
		return true;
	}
	//Return false of the withdrawal was unsuccessful
	return false;
}

bool SavingsAccount::depositMoney(Money amount) {
	//Check if amount to be deposited is positive
	if (amount.asCents() >= 0) {
		balance.add(amount);
		//Check for secondary deposit due to being a savings account
		if (secondDeposit == true) {
			balance.add(bonus);
			secondDeposit = false;
		}
		else {
			secondDeposit = true;
		}
		//Return true of the deposit was successful
		return true;
	}
	//Return false of the deposit was unsuccessful
	return false;
}

Money SavingsAccount::getBonusValue() const {
	//gives the bonus value of this object
	return this->bonus;
}

bool SavingsAccount::testWithdraw(Money amount) {
	//Helper function used to check whether or not a withdrawal can be completed; true if successful, false if unsuccessful
	if (balance.asCents() >= amount.asCents()) {
		return true;
	}
	return false;
}

bool SavingsAccount::testDeposit(Money amount) {
	//Helper function used to check whether or not a deposit can be completed; true if successful, false if unsuccessful
	return true;
}

SavingsAccount::~SavingsAccount() {
}


