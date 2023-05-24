#include <string>
#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_

class Customer {
private:
	//Added a few private class variables
	const std::string name; //Name of customer
	const int ID;			//ID of customer
	static int nextID;		//Iteration to keep ID unique

	Customer& operator=(const Customer &other);
    Customer(const Customer &other);

public:
	Customer(const std::string &name);
	std::string getName() const;
	int getID() const;
	virtual ~Customer();
};

#endif /* CUSTOMER_HPP_ */
