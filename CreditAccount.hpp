#include "Account.hpp"

#ifndef CREDITACCOUNT_HPP_
#define CREDITACCOUNT_HPP_

class CreditAccount : public Account {
private:
	CreditAccount& operator=(const CreditAccount &other);
    CreditAccount(const CreditAccount &other);
public:
	CreditAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	bool testWithdraw(Money amount);	//Helper function
	bool testDeposit(Money amount);		//Helper function
	virtual ~CreditAccount();
};

#endif /* CREDITACCOUNT_HPP_ */
