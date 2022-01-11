#pragma once
#include <iostream>
#include"User.h"
#include "Feedback.h"
#include "Product.h"
#include "Adress.h"
#include "Buyer.h"
#include "Array.h"
using namespace std;

class Dealer : virtual public User {
private:
	Array<Feedback> feedbacks;
	int feedbackSize;
	vector<Product *> products;
	vector<User *> buyers;
public:
	// C'tors
	Dealer();
	Dealer(char name[SIZE_NAME], char * password, Adress adress);
	Dealer( Dealer & other);
	Dealer(const User & other);

	// Setters
	void setProducts(vector<Product *>& const newProducts);
	void setBuyers(vector<User *>& newBuyers);

	// Getters
	Array<Feedback> getFeedbacks() const;
	vector<Product *> getProducts() const;
	vector<User *> getBuyers() const;

	//	Operators
	friend ostream & operator<<(ostream & os, const Dealer & dealer);
	
	// Functions
	void addFeedback(Feedback newFeedback);
	void addProduct(Product * newProduct);
	void addBuyer(User * newBuyer);

	~Dealer();
};