#include "Account.hpp"

#ifndef SAVINGSACCOUNT_HPP_
#define SAVINGSACCOUNT_HPP_

class SavingsAccount : public Account {
private:
	SavingsAccount& operator=(const SavingsAccount &other);
    SavingsAccount(const SavingsAccount &other);
    Money bonus;					//Class dependent object
    bool secondDeposit = false;		//Class dependent variable
public:
	SavingsAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	Money getBonusValue() const;
	bool testWithdraw(Money amount);	//Helper function
	bool testDeposit(Money amount);		//Helper function
	virtual ~SavingsAccount();
};

#endif /* SAVINGSACCOUNT_HPP_ */
