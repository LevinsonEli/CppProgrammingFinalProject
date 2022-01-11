#pragma once
#include <iostream>
using namespace std;

class Adress {
private:
	char * city;
	char * street;
	int houseNum;
	int flatNum;
public:
	// C'tors
	Adress();
	Adress(const char * city, const char * street, const int houseNum, const int flatNum);
	Adress(const Adress & other);

	// Setters
	void setCity(const char * newCity);
	void setStreet(const char * newStreet);
	void setHouseNum(const int newHouseNum);
	void setFlatNum(const int newFlatNum);

	// Getters
	char * getCity() const;
	char * getStreet() const;
	int getHouseNum() const;
	int getFlatNum() const;
	char * getAdressString() const;

	// Operators
	friend ostream & operator<<(ostream & os, const Adress & adress);

	//D'tor
	~Adress();
};