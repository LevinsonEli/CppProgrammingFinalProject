#pragma once
#include <iostream>
#include "User.h"
#include "Adress.h"
#include "Product.h"
using namespace std;

class Buyer : virtual public User {
private:
	vector<Product*> basket;
	float totalPrice;
public:
	// C'tors
	Buyer();
	Buyer(const char name[SIZE_NAME], const char * password, Adress adress);
	Buyer(const Buyer & other);
	Buyer(const User & other);

	void setBasket(vector<Product*> & const newBasket);
	void setTotalPrice(const float newTotalPrice);
	void makeBasketEmpty();

	vector<Product*> getBasket() const;
	float getTotalPrice() const;

	// Operators
	bool operator>(const Buyer & other) const;
	bool operator<(const Buyer & other) const;

	//Functions
	void addProductToBasket(Product * newProduct);
	void removeFromBasketByIndex(int index);

	// Operators
	friend ostream & operator<<(ostream & os, const Buyer & buyer);

	// D'tor
	~Buyer();
};