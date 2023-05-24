#ifndef TRANSACTION_HPP_
#define TRANSACTION_HPP_

#include <string>
#include "Account.hpp"
#include "Money.hpp"

enum TransactionState {
	COMPLETED,
	PENDING,
	FAILED
};

class Transaction {
private:
	//Private variables used in the class
    TransactionState state;
    int transactionID;
    static int nextID;
    Money amount;
    Account* Acc_1_Location;
    Account* Acc_2_Location;

	Transaction& operator=(const Transaction &other);
    Transaction(const Transaction &other);

public:
	Transaction(Account* fromAccount, Account* toAccount, Money amount);
	bool performTransaction();
	TransactionState getState() const;
	Money getAmount() const;
	Account* getFromAccount() const;
	Account* getToAccount() const;
	int getID() const;
	virtual ~Transaction();
};

#endif /* TRANSACTION_HPP_ */
