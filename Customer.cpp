#include "Customer.hpp"
#include <string>

int Customer::nextID = 0;

Customer::Customer(const std::string &name) : name(name), ID(nextID++) {
	//Initialises an object with a name and unique ID
}

std::string Customer::getName() const {
	//Returns this instances customer name
	return this->name;
}

int Customer::getID() const {
	//Returns this instances unique customer ID
	return this->ID;
}

Customer::~Customer() {
}

