#include "BuyerDealer.h"

// Operators
ostream & operator<<(ostream & os, const BuyerDealer & buyerDealer) {
	os << setfill(' ') << left << setw(20) << buyerDealer.getName();
	os << left << setw(30) << buyerDealer.getAdress() << endl;


	if (!buyerDealer.getBasket().empty()) {
		vector<Product *> basket = buyerDealer.getBasket();
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
	if (!buyerDealer.getProducts().empty()) {
		vector<Product *> products = buyerDealer.getProducts();
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
	if (buyerDealer.getFeedbacks().getSize() > 0) {
		Feedback * tempFeedbacks = buyerDealer.getFeedbacks().getArr();
		os << setfill(' ') << setw(15) << " ";
		os << "Feedbacks: " << endl;
		os << setfill(' ') << left << setw(15) << " " << setfill('-') << setw(85) << "-" << setfill(' ') << endl;
		os << setfill(' ') << setw(15) << " " << left << tempFeedbacks[0] << endl;
		for (int j = 1; j < buyerDealer.getFeedbacks().getSize(); j++) {
			os << setfill(' ') << setw(15) << " ";
			os << left << left << tempFeedbacks[j] << endl;
		}
	}
	return os;
}