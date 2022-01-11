#include "Buyer.h"

Buyer::Buyer() : User() {
	this->totalPrice = 0;
}

Buyer::Buyer(const char name[SIZE_NAME], const char * password, Adress adress) : User (name, password, adress) {
	this->totalPrice = 0;
}
Buyer::Buyer(const User & other) : User(other) {
	this->totalPrice = 0;
}
Buyer::Buyer(const Buyer & other) : User(other) {
	if (!other.basket.empty()) {
		for (int i = 0; i < other.getBasket().size(); i++)
			this->basket.push_back(other.getBasket()[i]);
	}
	this->totalPrice = other.totalPrice;
}

void Buyer::setBasket( vector<Product*>& const newBasket) {
	this->basket.clear();
	if (!newBasket.empty()) {
		for (int i = 0; i < newBasket.size(); i++)
			this->basket.push_back(newBasket[i]);
	}
}
void Buyer::makeBasketEmpty() {
	this->basket.clear();
}
void Buyer::setTotalPrice(const float newTotalPrice) {
	this->totalPrice = newTotalPrice;
}
vector<Product*> Buyer::getBasket() const {
	return this->basket;
}
float Buyer::getTotalPrice() const {
	return this->totalPrice;
}


// Operators
bool Buyer::operator>(const Buyer & other) const {
	return this->totalPrice > other.getTotalPrice();
}
bool Buyer::operator<(const Buyer & other) const {
	return this->totalPrice < other.getTotalPrice();
}


void Buyer::addProductToBasket(Product * newProduct) {	// pointer
	this->basket.push_back(newProduct);
	this->totalPrice += newProduct->getPrice();
}
void Buyer::removeFromBasketByIndex(int index) {
	vector<Product *>::iterator itr = this->basket.begin();
	itr += index;
	this->basket.erase(itr);
}

// Operators
ostream & operator<<(ostream & os, const Buyer & buyer) {
	os << setfill(' ') << left << setw(20) << buyer.getName();
	os << buyer.getAdress() << endl;

	if (!buyer.basket.empty()) {
		vector<Product *> basket = buyer.getBasket();
		os << setfill(' ') << setw(30) << " ";
		os << "Products in cart " << endl;
		os << setfill(' ') << setw(30) << " ";
		os << left << setw(20) << "Name: " << "Price:  " << "Category:   " << "Id: " << endl;
		os << setfill(' ') << left << setw(30) << " " << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
		os << setfill(' ') << setw(30) << " " << left << setw(20) << *basket[0] << endl;
		for (int i = 1; i < basket.size(); i++) {
			os << setfill(' ') << setw(30) << " " << left << setw(20) << *basket[i] << endl;
		}
	}
	return os;
}

Buyer::~Buyer() { 
}