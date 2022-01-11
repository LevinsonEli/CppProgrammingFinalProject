#pragma once
#include "Adress.h"
#include "Product.h"
#include "Feedback.h"

class User {
private:
	char name[20];
	char * password;
	Adress adress;
public:
	// C'tors
	User();
	User(const char name[20], const char * password, Adress adress);
	User(char const * name, char * password, Adress adress);
	User(const User&other);
	User(ifstream & in);

	virtual void save(ofstream & out) const {
		out.write((const char*)this, sizeof(*this));
	}


	// Setters
	void setName(const char newName[SIZE_NAME]);
	void setPassword(const char * newPassword);
	void setAdress( Adress newAdress);

	// Getters
	char const * getName() const;
	char * getPassword() const;
	Adress getAdress() const;

	virtual ~User();
};