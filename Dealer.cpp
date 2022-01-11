#include "Dealer.h"

// C'tors
Dealer::Dealer() {
	this->feedbacks = Array<Feedback>();
}

Dealer::Dealer(char name[SIZE_NAME], char * password, Adress adress) : User(name, password, adress) {
	this->feedbacks = Array<Feedback>();
}
Dealer::Dealer(Dealer & other) : User(other) {
	this->feedbacks = Array<Feedback>(other.feedbacks);
	setProducts(other.products);
	setBuyers(other.buyers);
}
Dealer::Dealer(const User & other) : User(other) {
	this->feedbacks = Array<Feedback>();
}

// Setters
void Dealer::setProducts(vector<Product *>& const newProducts) {
	this->products.clear();
	//this->products->reserve(newProducts->capacity());
	for (int i = 0; i < newProducts.size(); i++) {
		this->products.push_back(newProducts[i]);
	}
}
void Dealer::setBuyers( vector<User *>& newBuyers) {
	this->buyers.clear();
	//this->buyers->reserve(newBuyers->capacity());
	for (int i = 0; i < newBuyers.size(); i++) {
		this->buyers.push_back(newBuyers[i]);
	}
}

// Getters
Array<Feedback> Dealer::getFeedbacks() const {
	return this->feedbacks;
}
vector<Product *> Dealer::getProducts() const {
	return this->products;
}
vector<User *> Dealer::getBuyers() const {
	return this->buyers;
}

//	Operators
ostream & operator<<(ostream & os, const Dealer & dealer) {
	os << setfill(' ') << left << setw(20) << dealer.getName();
	os << dealer.getAdress() << endl;

	if (!dealer.products.empty()) {
		vector<Product *> products = dealer.getProducts();
		os << setfill(' ') << setw(30) << " ";
		os << "Products " << endl;
		os << setfill(' ') << setw(30) << " ";
		os << left << setw(20) << "Name: " << "Price:  " << "Category:   " << "Id: " << endl;
		os << setfill(' ') << left << setw(30) << " " << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
		os << setfill(' ') << setw(30) << " " << left << setw(20) << *products[0] << endl;
		for (int i = 1; i < products.size(); i++) {
			os << setfill(' ') << setw(30) << " " << left << setw(20) << *products[i] << endl;
		}
	}
	if (dealer.feedbacks.getSize() > 0) {
		os << setfill(' ') << setw(15) << " ";
		os << "Feedbacks: " << endl;
		os << setfill(' ') << left << setw(15) << " " << setfill('-') << setw(85) << "-" << setfill(' ') << endl;
		os << setfill(' ') << setw(15) << " " << left << dealer.feedbacks.getArr()[0] << endl;
		for (int j = 1; j < dealer.feedbacks.getSize(); j++) {
			os << setfill(' ') << setw(15) << " ";
			os << left << left << dealer.feedbacks.getArr()[j] << endl;
		}
	}
	return os;
}

// Functions
void Dealer::addFeedback(Feedback newFeedback) {
	this->feedbacks += newFeedback;
}
void Dealer::addProduct(Product * newProduct) {
	this->products.push_back(newProduct);
}
void Dealer::addBuyer(User * newBuyer) {
	this->buyers.push_back(newBuyer);
}
Dealer::~Dealer() {
}