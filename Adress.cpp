#include "Adress.h"

Adress::Adress() {
	this->city = nullptr;
	this->street = nullptr;
	this->houseNum = 0;
	this->flatNum = 0;
}
Adress::Adress(const char * city, const char * street, const int houseNum, const int flatNum) {
	this->city = new char[strlen(city) + 1];
	strcpy(this->city, city);
	this->city[strlen(city)] = '\0';
	this->street = new char[strlen(street) + 1];
	strcpy(this->street, street);
	this->street[strlen(street)] = '\0';
	this->houseNum = houseNum;
	this->flatNum = flatNum;
}
Adress::Adress(const Adress & other) {
	this->city = new char[strlen(other.city) + 1];
	strcpy(this->city, other.city);
	this->city[strlen(other.city)] = '\0';
	this->street = new char[strlen(other.street) + 1];
	strcpy(this->street, other.street);
	this->street[strlen(other.street)] = '\0';
	this->houseNum = other.houseNum;
	this->flatNum = other.flatNum;
}

void Adress::setCity(const char * newCity) {
	delete [] this->city;
	this->city = new char[strlen(newCity) + 1];
	strcpy(this->city, newCity);
	this->city[strlen(newCity)] = '\0';
}
void Adress::setStreet(const char * newStreet) {
	delete [] this->street;
	this->street = new char[strlen(newStreet) + 1];
	strcpy(this->street, newStreet);
	this->street[strlen(newStreet)] = '\0';
}
void Adress::setHouseNum(const int newHouseNum) {
	this->houseNum = newHouseNum;
}
void Adress::setFlatNum(const int newFlatNum) {
	this->flatNum = newFlatNum;
}

char * Adress::getCity() const {
	return this->city;
}
char * Adress::getStreet() const {
	return this->street;
}
int Adress::getHouseNum() const {
	return this->houseNum;
}
int Adress::getFlatNum() const {
	return this->flatNum;
}
char * Adress::getAdressString() const {
	char * adress = new char[strlen(this->city) + strlen(this->street) + 100];
	sprintf(adress, "%s, %s %d/%d", this->city, this->street, this->houseNum, this->flatNum);
	return adress;
}

// Operators
ostream & operator<<(ostream & os, const Adress & adress) {
	os << adress.getCity() << ", " << adress.getStreet() << " " 
		<< adress.getHouseNum() << "/" << adress.getFlatNum();
	return os;
}

Adress::~Adress() {
	delete [] this->city;
	delete [] this->street;
}