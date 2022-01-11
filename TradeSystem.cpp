#include "TradeSystem.h"

// C'tors
TradeSystem::TradeSystem() {
	strcpy(this->name, "\0");
}

// Getters
char const * TradeSystem::getName() const {
	return this->name;
}
vector<User *> TradeSystem::getUsers() const {
	return this->users;
}

// Operatorts
const TradeSystem & TradeSystem::operator+=(const Buyer & newBuyer) {
	User * newUser = new Buyer(newBuyer);
	addUser(newUser);
	return *this;
}
const TradeSystem & TradeSystem::operator+=(const Dealer & newDealer) {
	User * newUser = new Dealer(newDealer);
	addUser(newUser);
	return *this;
}
const TradeSystem & TradeSystem::operator+=(const BuyerDealer & newBuyerDealer) {
	User * newUser = new BuyerDealer(newBuyerDealer);
	addUser(newUser);
	return *this;
}

// Functions
void TradeSystem::addUser(User * newDealer) {
	if (newDealer != nullptr) {
		User * newUser;
		if (strcmp(typeid(*newDealer).name(), typeid(Buyer).name()) == 0)
			newUser = new Buyer(*(dynamic_cast<Buyer*>(newDealer)));
		else if (strcmp(typeid(*newDealer).name(), typeid(Dealer).name()) == 0)
			newUser = new Dealer(*(dynamic_cast<Dealer*>(newDealer)));
		else if (strcmp(typeid(*newDealer).name(), typeid(BuyerDealer).name()) == 0)
			newUser = new BuyerDealer(*(dynamic_cast<BuyerDealer*>(newDealer)));
		this->users.push_back(newUser);
	}
}

TradeSystem::~TradeSystem() {
}