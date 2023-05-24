#ifndef ACCOUNT_HPP_
#define ACCOUNT_HPP_
#include "Money.hpp"
class Account{
protected:
	//Protected class variables so they can be used for inherited classes
	int customerID;		//Customer ID (not unique)
	int accountID;		//Account ID (unique)
	static int nextID;	//Iteration on ID to allow for unique IDs
	Money balance;		//Balance of a specific account object
private:
	Account& operator=(const Account &other);
	Account(const Account &other);
public:
	Account(const int customerID);
	virtual bool withdrawMoney(Money amount) = 0;
	virtual bool depositMoney(Money amount) = 0;
	int getCustomerID() const;
	int getAccountID() const;
	Money getBalance() const;
	virtual bool testWithdraw(Money amount) = 0;	//Virtual Helper Function
	virtual bool testDeposit(Money amount) = 0;		//Virtual Helper Function
	virtual ~Account();
};

#endif /* ACCOUNT_HPP_ */
