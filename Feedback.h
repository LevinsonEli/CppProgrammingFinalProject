#pragma once
#include <iostream>
#include <time.h>
#include "Product.h"
using namespace std;

class Feedback {
private:
	char buyerName[SIZE_NAME];
	time_t date;
	char * message;
public:
	// C'tors
	Feedback();
	Feedback(const char name[SIZE_NAME], const char *  message);
	Feedback(const Feedback & other);
	
	// Setters
	void setBuyerName(const char newName[SIZE_NAME]);
	void setMessage(const char * newMessage);

	// Getters
	char const * getBuyerName() const ;
	time_t getDate() const;
	char * getDateString() const;
	char * getMessage() const;

	// Operators
	friend ostream & operator<<(ostream & os, const Feedback & feedback);
	const Feedback & operator=(const Feedback & other);

	// D'tor
	~Feedback();
};
