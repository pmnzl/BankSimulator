#include "Account.hpp"

#ifndef CHEQUEACCOUNT_HPP_
#define CHEQUEACCOUNT_HPP_

class ChequeAccount : public Account {
private:
	ChequeAccount& operator=(const ChequeAccount &other);
    ChequeAccount(const ChequeAccount &other);
    Money transaction_fee;				//Class independent transaction fee
    Money* trans = &transaction_fee;	//Pointer to location of 'transaction_fee'
public:
	ChequeAccount(const int customerID);
	bool withdrawMoney(Money amount);
	bool depositMoney(Money amount);
	Money* getTransactionFee() const;
	bool testWithdraw(Money amount);	//Helper function
	bool testDeposit(Money amount);		//Helper function
	virtual ~ChequeAccount();
};

#endif /* CHEQUEACCOUNT_HPP_ */
