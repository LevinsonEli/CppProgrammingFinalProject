#include "Product.h"

// C'tors
Product::Product() {
	this->category = CHILDREN;
	strcpy(this->name, "\0");
	this->price = 0;
	this->productId = uniqueId++;
}
Product::Product(const eCategory category, const char name[SIZE_NAME], const  float price) {
	this->category = category;
	strcpy(this->name, name);
	this->price = price;
	this->productId = uniqueId++;
}
Product::Product(const Product & other) {
	this->category = other.category;
	strcpy(this->name, other.name);
	this->price = other.price;
	this->productId = other.productId;
}

// Setters
void Product::setCategory(const eCategory newCategory) {
	this->category = newCategory;
}
void Product::setName(const char newName[SIZE_NAME]) {
	strcpy(this->name, newName);
}
void Product::setPrice(const float newPrice) {
	this->price = newPrice;
}

// Getters
eCategory Product::getCategory() const {
	return this->category;
}
char const * Product::getCategoryString() const {
	char * categoryStr = new char[11];
	if (this->category == 0)
		strcpy(categoryStr, "CHILDREN");
	else if (this->category == 1)
		strcpy(categoryStr, "ELECTRICITY");
	else if (this->category == 2)
		strcpy(categoryStr, "OFFICE");
	else
		strcpy(categoryStr, "CLOTHES");
	return categoryStr;
}
char const * Product::getName() const {
	return this->name;
}
float Product::getPrice() const {
	return this->price;
}
int Product::getProductId() const {
	return this->productId;
}

// Operators
ostream & operator<<(ostream & os, const Product & product) {
	os << product.getName() << setprecision(2) << setw(8) << product.getPrice() <<
		setw(12) << product.getCategoryString() << product.getProductId();
	return os;
}