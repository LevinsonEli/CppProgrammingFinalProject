#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include<iomanip>
using namespace std;

const int SIZE_NAME = 20;

enum eCategory { CHILDREN, ELECTRICITY, CLOTHES, OFFICE };
static int uniqueId = 0;
class Product {
private:
	eCategory category;
	char name[20];
	float price;
	int productId;

public:
	// C'tors
	Product();
	Product(const eCategory category, const char name[SIZE_NAME], const float price);
	Product(const Product & other);

	// Setters
	void setCategory(const eCategory newCategory);
	void setName(const char newName[SIZE_NAME]);
	void setPrice(const float newPrice);

	// Getters
	eCategory getCategory() const;
	char const * getCategoryString() const;
	char const * getName() const;
	float getPrice() const;
	int getProductId() const;

	// Operators
	friend ostream & operator<<(ostream & os, const Product & product);
};
