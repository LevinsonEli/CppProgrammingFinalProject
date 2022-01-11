#include "Feedback.h"

// C'tors
Feedback::Feedback() {
	strcpy(this->buyerName, "\0");
	this->date = time(0);
	message = nullptr;
}
Feedback::Feedback(const char name[SIZE_NAME], const char * message) {
	strcpy(this->buyerName, name);
	this->date = time(0);
	this->message = new char[strlen(message) + 1];
	strcpy(this->message, message);
}
Feedback::Feedback(const Feedback & other) {
	strcpy(this->buyerName, other.buyerName);
	this->date = other.date;
	this->message = new char[strlen(other.message) + 1];
	strcpy(this->message, other.message);
}

// Setters
void Feedback::setBuyerName(const char newName[SIZE_NAME]) {
	strcpy(this->buyerName, newName);
}

void Feedback::setMessage(const char * newMessage) {
	delete[] this->message;
	this->message = new char[strlen(newMessage) + 1];
	strcpy(this->message, newMessage);
}

// Getters
char const * Feedback::getBuyerName() const{
	return this->buyerName;
}
time_t Feedback::getDate() const {
	return this->date;
}
char * Feedback::getDateString() const {
	char * dateStr = new char[50];
	sprintf(dateStr, "%s", ctime(&this->date));
	return dateStr;
}
char * Feedback::getMessage() const {
	return this->message;
}

// Operators
ostream & operator<<(ostream & os, const Feedback & feedback) {
	os << feedback.getBuyerName() << ": " << feedback.getMessage();
	return os;
}
const Feedback & Feedback::operator=(const Feedback & other) {
	strcpy(this->buyerName, other.buyerName);
	delete[] this->message;
	this->message = new char[strlen(other.message)];
	strcpy(this->message, other.message);
	this->date = other.date;
	return *this;
}

Feedback::~Feedback() { 
	delete[] this->message;
}