#include "User.h"

// C'tors
User::User() : adress(){
	strcpy(this->name, "\0");
	this->password = new char[1];
	this->password[0] = '\0';
}
User::User(const char name[20], const char * password, Adress adress) : adress(adress) {
	strcpy(this->name, name);
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
	this->password[strlen(password)] = '\0';
}

User::User(char const * name, char * password, Adress adress) : adress(adress) {
	strcpy(this->name, name);
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
	this->password[strlen(password)] = '\0';
}
User::User(const User&other) : adress(other.adress) {
	strcpy(this->name, other.name);
	this->password = new char[strlen(other.password) + 1];
	strcpy(this->password, other.password);
	this->password[strlen(other.password)] = '\0';
}
User::User(ifstream & in) {
	in.read((char *) this, sizeof(*this));
}

// Setters
void User::setName(const char newName[SIZE_NAME]) {
	strcpy(this->name, newName);
}
void User::setPassword(const char * newPassword) {
	delete[] this->password;
	this->password = new char[strlen(newPassword) + 1];
	strcpy(this->password, newPassword);
	this->password[strlen(newPassword)] = '\0';
}
void User::setAdress(Adress newAdress) {
	this->adress = Adress();
}

// Getters
char const * User::getName() const {
	return this->name;
}
char * User::getPassword() const {
	return this->password;
}
Adress User::getAdress() const {
	return this->adress;
}

User::~User() {
	delete[]this->password;
}