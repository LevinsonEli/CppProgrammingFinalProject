#pragma once
#include <iostream>
#include "User.h"
#include "Buyer.h"
#include "Dealer.h"
#include "BuyerDealer.h"

class TradeSystem {
private: 
	char name[SIZE_NAME];
	vector<User *> users;
public:
	// C'tors
	TradeSystem();

	// Getters
	char const * getName() const;
	vector<User *> getUsers() const;

	// Operatorts
	const TradeSystem & operator+=(const Buyer & newBuyer);
	const TradeSystem & operator+=(const Dealer & newDealer);
	const TradeSystem & operator+=(const BuyerDealer & newBuyerDealer);

	// Functions
	void addUser(User * newDealer);

	// D'tor
	~TradeSystem();
};