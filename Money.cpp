
#include "Money.hpp"

Money::Money() : totalCents(0) {
}

Money::Money(int dollars, int cents) {
	//Removed code to check if a money object is negative to allow for a money object to be negative
	this->totalCents = dollars*100 + cents;
}

int Money::getDollars() const {
	return totalCents/100;
}

int Money::getCents() const {
	return totalCents%100;
}

int Money::asCents() const {
	return totalCents;
}

void Money::addDollars(int dollars) {
	if (dollars > 0) {
		this->totalCents += dollars*100;
	}
}

void Money::addCents(int cents) {
	if (cents > 0) {
		this->totalCents += cents;
	}
}

void Money::subtractDollars(int dollars) {
	if (dollars > 0) {
		this->totalCents -= dollars*100;
	}
}

void Money::subtractCents(int cents) {
	if (cents > 0) {
		this->totalCents -= cents;
	}
}

void Money::add(const Money &other) {
	//Now allows for negative money objects but not for the 'other' variable
	if (other.totalCents >= 0){
		this->totalCents += other.totalCents;
	}
}

void Money::subtract(const Money &other) {
	//Now allows for negative money objects but not for the 'other' variable
	if (other.totalCents >= 0) {
		this->totalCents -= other.totalCents;
	}
}

void Money::split(Money &other) {
	int newTotal = (this->totalCents + other.totalCents)/2;
	this->totalCents = newTotal;
	other.totalCents = newTotal;
}

Money::~Money() {
}
