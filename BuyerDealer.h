#pragma once
#include "Buyer.h"
#include "Feedback.h"
#include "Product.h"
#include "Adress.h"
#include "Buyer.h"
#include "Dealer.h"

class BuyerDealer : virtual public User, public Buyer, public Dealer {
private:
public:
	// C'tors
	BuyerDealer() : User(), Buyer(), Dealer() {} 
	BuyerDealer(char name[SIZE_NAME], char * password, Adress adress) : User(name, password, adress), Buyer(), Dealer() {}
	BuyerDealer(const BuyerDealer & other) : User(other.getName(), other.getPassword(), other.getAdress()), Buyer(other), Dealer(other) {}
	BuyerDealer(const User & other) : User(other), Buyer(other), Dealer(other) {}

	// Operators
	friend ostream & operator<<(ostream & os, const BuyerDealer & buyerDealer);
};