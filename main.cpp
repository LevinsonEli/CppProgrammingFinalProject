#include "TradeSystem.h"
#include <iomanip>

enum eUserStatus { DEALER, BUYER, BUYERDEALER };

/* Function that get a string from the keyboard and returns it. */
char * getStringFromKeyboard(int size);

/* Function that gets an adress from the keyboard and returns it. */
Adress getAdressFromKeyboard(eUserStatus userStatus);
/* Function that gets a [roduct from the keyboard and returns it. */
Product * getProductFromKeyboard();
/* Function that gets a feedback from the keyboard and returns it. */
Feedback * getFeedbackFromKeyboard(const char name[SIZE_NAME]);
/* Function that gets a buyer's information from the keyboard and returns it. */
Buyer * getBuyerFromKeyboard(TradeSystem * mySystem);
/* Function that gets a dealer's information from the keyboard and returns it. */
Dealer * getDealerFromKeyboard(TradeSystem * mySystem);
BuyerDealer * getBuyerDealerFromKeyboard(TradeSystem * mySystem);

/* Funtion that adds a new dealer to the system. */
void addDealerToSystem(TradeSystem * mySystem);
/* Function that adds a new buyer to the system. */
void addBuyerToSystem(TradeSystem * mySystem);
/* Function that adds a new buyer-dealer to the system. */
void addBuyerDealerToSystem(TradeSystem * mySystem);

/* Function that adds a new product to a dealer. */
void addProductToDealer(TradeSystem * mySystem);
/* Function that adds a new feedback to a delaer. */
void addFeedbackToDealer(TradeSystem * mySystem);
/* Function that adds a new product to a buyer's cart. */
void addProductToBuyersBasket(TradeSystem * mySystem);

/* Function that performs order for a buyer. */
void performOrder(TradeSystem * mySystem);
/* Function that gets pay for the order of a buyer. */
void payForOrder(TradeSystem * mySystem);

/* Function that prints all the buyers and if bdPrint is true also all the buyer-dealers. */
void printAllBuyers(TradeSystem * mySystem, bool bdPrint);
/* Function that prints all the dealers and if bdPrint is true also all the buyer-dealers. */
void printAllDealers(TradeSystem * mySystem, bool bdPrint);
/* Function that prints all the buyer-dealers. */
void printAllBuyerDealers(TradeSystem * mySystem);

/* Function that searches a product and prints all the products with the same name. */
void printSearchedProduct(TradeSystem * mySystem);
/* Function that prints a certain class of user ( buyer, dealer, buyer-dealer ). */
void printCertainClass(TradeSystem * mySystem);

/* Function that checks < and > operator of Buyer class. */
void checkOperators(TradeSystem * mySystem);
void exitFunction(TradeSystem * mySystem, const char * fileName);

int main() {
	TradeSystem * mySystem = new TradeSystem();

	// Here is an example of writing and reading to file (that works perfect)

	//ofstream outFile("file.dat", ios::binary | ios::trunc);
	//User *user = new Buyer("1", "1", Adress("a", "a", 1, 1));
	//outFile << typeid(*user).name() << '\0';
	//(dynamic_cast<User *>(user))->save(outFile);
	//outFile.close();

	ifstream inFile("file.dat", ios::binary);
	char *className = new char[256];

	//inFile.getline(className, 256, '\0');
	//User * user2 = new Buyer(inFile);
	//cout << className << endl;
	//cout << user2->getName() << endl;
	//cout << user2->getAdress() << endl;
	//cout << user2->getPassword() << endl;

	if (inFile.is_open()) {
		while (!inFile.eof()) {
			inFile.getline(className, 256, '\0');
			User * user;
			if (strcmp(className, "class Buyer") == 0) {
				user = new Buyer(inFile);
			}
			else if (strcmp(className, "class Dealer") == 0) {
				user = new Dealer(inFile);
			}
			else if (strcmp(className, "class BuyerDealer") == 0) {
				user = new BuyerDealer(inFile);
			}
			else {
				break;
			}
			mySystem->addUser(user);
		}
	}
	inFile.close();

	int menuChoice = 0;
	try {
		while (menuChoice != 15) {
			cout << "1. Add buyer " << endl;
			cout << "2. Add dealer " << endl;
			cout << "3. Add buyer/dealer " << endl;
			cout << "4. Add product to dealer " << endl;
			cout << "5. Add feedback to dealer " << endl;
			cout << "6. Add product to cart " << endl;
			cout << "7. Perform order " << endl;
			cout << "8. Pay for order " << endl;
			cout << "9. Print all buyers " << endl;
			cout << "10. Print all dealers " << endl;
			cout << "11. Print all buyer-dealers " << endl;
			cout << "12. Print certain class of users " << endl;
			cout << "13. Search product " << endl;
			cout << "14. Compare two buyers " << endl;
			cout << "15. Exit " << endl;

			cin >> menuChoice;
			cin.ignore(256, '\n');
			switch (menuChoice) {
			case 1: addBuyerToSystem(mySystem); break;
			case 2: addDealerToSystem(mySystem); break;
			case 3: addBuyerDealerToSystem(mySystem); break;
			case 4: addProductToDealer(mySystem); break;
			case 5: addFeedbackToDealer(mySystem); break;
			case 6: addProductToBuyersBasket(mySystem); break;
			case 7: performOrder(mySystem); break;
			case 8: payForOrder(mySystem); break;
			case 9: printAllBuyers(mySystem, true); break;
			case 10: printAllDealers(mySystem, true); break;
			case 11: printAllBuyerDealers(mySystem); break;
			case 12: printCertainClass(mySystem); break;
			case 13: printSearchedProduct(mySystem); break;
			case 14: checkOperators(mySystem); break;
			case 15: exitFunction(mySystem, "file.dat"); break;
			default: throw "Incorrect menu choice"; break;
			}
		}
	}
	catch (const char * str) {
		cout << str << endl;
	}
	catch (...) {
		cout << "Some error occured. " << endl;
	}

	system("pause");
	return 0;
}

void exitFunction(TradeSystem * mySystem, const char * fileName) {
	ofstream outFile(fileName, ios::binary | ios::trunc);
	vector<User *> users = mySystem->getUsers();
	for (int i = 0; i < mySystem->getUsers().size(); i++) {
		outFile << typeid(*users[i]).name() << '\0';
		(dynamic_cast<User *>(users[i]))->save(outFile);
	}
	outFile.close();
}
char * getStringFromKeyboard(int size) {
	if (size > 0) {
		char * str = new char[size + 1];
		int i = 0;
		while (i != size) {
			cin.get(str[i]);
			if (str[i] == '\n')
				break;
			i++;
		}
		fflush(stdin);
		str[i] = '\0';
		return str;
	}
	else
		throw "String's size must be a positive integer. ";
}
Adress getAdressFromKeyboard(eUserStatus userStatus) {
	char userStatusName[15];
	if (userStatus == DEALER)
		strcpy(userStatusName, "dealer\0");
	else if (userStatus == BUYER)
		strcpy(userStatusName, "buyer\0");
	else if (userStatus == BUYERDEALER)
		strcpy(userStatusName, "buyer/dealer\0");
	else
		throw "Incorrect user's status";

	char * city = new char[256];
	char * street = new char[256];
	int houseNum;
	int flatNum;

	cout << "Enter " << userStatusName << "'s city: ";
	city = getStringFromKeyboard(256);
	if (strcmp(city, "") == 0)
		throw "City can't be an empty string";
	cout << "Enter " << userStatusName << "'s street: ";
	street = getStringFromKeyboard(256);
	if (strcmp(street, "") == 0)
		throw "Street can't be an empty string";
	cout << "Enter " << userStatusName << "'s house number: (numbers only) ";
	cin >> houseNum;
	cin.ignore(256, '\n');
	cout << "Enter " << userStatusName << "'s flat number: (numbers only) ";
	cin >> flatNum;
	cin.ignore(256, '\n');
	return Adress(city, street, houseNum, flatNum);
}
Product * getProductFromKeyboard() {
	char name[SIZE_NAME];
	float price;
	int category = -1;

	cout << "Enter product's name: ";
	strcpy(name, getStringFromKeyboard(SIZE_NAME));
	cout << "Enter product's price: ";
	cin >> price;
	cin.ignore(256, '\n');
	if (price <= 0) {
		throw "The price must be a positive number. ";
	}

	while (category < 0 || category > 3) {
		cout << "Enter product's category: " << endl;
		cout << "(0 - CHILDREN, 1 - ELECTRICITY, 2 - OFFICE, 3 - CLOTHES)" << endl;
		cin >> category;
		cin.ignore(256, '\n');
	}

	return new Product(eCategory(category), name, price);
}
Feedback * getFeedbackFromKeyboard(const char name[SIZE_NAME]) {
	cout << "Enter you feedback. Press 'enter' for end. " << endl;
	return new Feedback(name, getStringFromKeyboard(256));
}
Buyer * getBuyerFromKeyboard(TradeSystem * mySystem) {
	char name[SIZE_NAME];
	char * password = new char[256];

	cout << "Enter buyer's name: ";
	strcpy(name, getStringFromKeyboard(SIZE_NAME));
	if (strlen(name) == 0)
		throw "Name can't be an empty string.";

	if (!mySystem->getUsers().empty()) {
		for (int i = 0; i < mySystem->getUsers().size(); i++) {
			if (strcmp(typeid(*mySystem->getUsers()[i]).name(), typeid(Buyer).name()) == 0 && strcmp(name, (mySystem->getUsers()[i])->getName()) == 0) {
				throw "Buyer with such a name already exist. ";
			}
		}
	}

	cout << "Enter buyer's password (press enter for end): ";
	password = getStringFromKeyboard(256);

	return new Buyer(name, password, getAdressFromKeyboard(BUYER));
}
Dealer * getDealerFromKeyboard(TradeSystem * mySystem) {
	char name[SIZE_NAME];
	char * password = new char[256];

	cout << "Enter dealer's name: ";
	strcpy(name, getStringFromKeyboard(SIZE_NAME));
	if (strlen(name) == 0)
		throw "Name can't be an empty string.";

	if (!mySystem->getUsers().empty()) {
		for (int i = 0; i < mySystem->getUsers().size(); i++) {
			if (strcmp(typeid(*mySystem->getUsers()[i]).name(), typeid(Dealer).name()) == 0 && strcmp(name, (mySystem->getUsers()[i])->getName()) == 0) {
				throw "Dealer with such a name already exist. ";
			}
		}
	}

	cout << "Enter dealer's password (press enter for end): ";
	password = getStringFromKeyboard(256);

	return new Dealer(name, password, getAdressFromKeyboard(DEALER));
}

BuyerDealer * getBuyerDealerFromKeyboard(TradeSystem * mySystem) {
	char name[SIZE_NAME];
	char * password = new char[256];

	cout << "Enter buyer/dealer's name: ";
	strcpy(name, getStringFromKeyboard(SIZE_NAME));
	if (strlen(name) == 0)
		throw "Name can't be an empty string.";

	if (!mySystem->getUsers().empty()) {
		for (int i = 0; i < mySystem->getUsers().size(); i++) {
			if (strcmp(name, (mySystem->getUsers()[i])->getName()) == 0) {
				throw "Buyer or Dealer with such a name already exist. ";
			}
		}
	}
	cout << "Enter buyer/dealer's password (press enter for end): ";
	password = getStringFromKeyboard(256);

	return new BuyerDealer(name, password, getAdressFromKeyboard(BUYERDEALER));
}

void performOrder(TradeSystem * mySystem) {
	if (!mySystem->getUsers().empty()) {
		char name[SIZE_NAME];
		cout << "Enter buyer's name: ";
		strcpy(name, getStringFromKeyboard(SIZE_NAME));
		for (int i = 0; i < mySystem->getUsers().size(); i++) {
			if (strcmp(typeid(*mySystem->getUsers()[i]).name(), typeid(Dealer).name()) != 0 && strcmp(name, (mySystem->getUsers()[i])->getName()) == 0) { // buyer or buyer/dealer
				if (!(dynamic_cast<Buyer *>(mySystem->getUsers()[i])->getBasket().empty())) {
					int num = -2;
					while (num != -1 && (!dynamic_cast<Buyer *>(mySystem->getUsers()[i])->getBasket().empty())) {
						vector<Product *> basket = (dynamic_cast<Buyer *>(mySystem->getUsers()[i]))->getBasket();
						cout << "Here is your cart: " << endl;
						for (int j = 0; j < basket.size(); j++) {
							cout << j << ". " << (basket[j])->getName() << " " << (basket[j])->getPrice() << endl;
						}
						cout << "To remove product from the cart enter it's number. For exit enter -1 " << endl;
						cin >> num;
						cin.ignore(256, '\n');
						if (num < 0 || num >= (dynamic_cast<Buyer *>(mySystem->getUsers()[i]))->getBasket().size())
							break;
						else
							(dynamic_cast<Buyer *>(mySystem->getUsers()[i]))->removeFromBasketByIndex(num);
					}
				}
				else
					cout << "No products in the cart. " << endl;
				return;
			}
		}
		cout << "No such a buyer. " << endl;
	}
	else
		cout << "No buyers for performing order. " << endl;
}

void payForOrder(TradeSystem * mySystem) {
	if (!mySystem->getUsers().empty()) {
		vector<User *> users = mySystem->getUsers();
		char name[SIZE_NAME];
		cout << "Enter buyer's name: ";
		strcpy(name, getStringFromKeyboard(SIZE_NAME));

		for (int i = 0; i < users.size(); i++) {
			if (strcmp(typeid(*users[i]).name(), typeid(Dealer).name()) != 0 && strcmp(name, (users[i])->getName()) == 0) { // buyer or buyer/dealer
				if (!(dynamic_cast<Buyer *>(users[i]))->getBasket().empty()) {
					vector<Product *> basket = (dynamic_cast<Buyer *>(users[i]))->getBasket();
					for (int j = 0; j < basket.size(); j++) {
						for (int h = 0; h < users.size(); h++) {
							if (strcmp(typeid(*users[h]).name(), typeid(Dealer).name()) == 0) {
								vector<Product *> products = (dynamic_cast<Dealer *>(users[h]))->getProducts();
								for (int g = 0; g < products.size(); g++) {
									if ((basket[j])->getProductId() == products[g]->getProductId()) {
										(dynamic_cast<Dealer *>(users[h]))->addBuyer(users[i]);
										break;
									}
								}
							}
						}
					}
					(dynamic_cast<Buyer *>(users[i]))->makeBasketEmpty();
				}
				else
					cout << "No products in the cart. " << endl;
				return;
			}
		}
		cout << "No such a buyer. " << endl;
	}
	else
		cout << "No buyers in the system. " << endl;
}
void addDealerToSystem(TradeSystem * mySystem) {
	Dealer * newBuyer = getDealerFromKeyboard(mySystem);
	if (newBuyer != nullptr)
		(*mySystem) += *newBuyer;
}

void addBuyerToSystem(TradeSystem * mySystem) {
	Buyer * newDealer = getBuyerFromKeyboard(mySystem);
	if (newDealer != nullptr)
		(*mySystem) += *newDealer;
}

void addBuyerDealerToSystem(TradeSystem * mySystem) {
	BuyerDealer * newBuyerDealer = getBuyerDealerFromKeyboard(mySystem); 
	if (newBuyerDealer != nullptr)
		(*mySystem) += *newBuyerDealer;
}

void addProductToDealer(TradeSystem * mySystem) {
	char dealerName[SIZE_NAME];
	cout << "Enter dealer's name: ";
	strcpy(dealerName, getStringFromKeyboard(SIZE_NAME));

	if (!mySystem->getUsers().empty()) {
		vector<User *> users = mySystem->getUsers();
		for (int i = 0; i < users.size(); i++) {
			if (strcmp(typeid(*users[i]).name(), typeid(Buyer).name()) != 0 && strcmp((users[i])->getName(), dealerName) == 0) { // dealer or buyer/dealer
				(dynamic_cast<Dealer *> (users[i]))->addProduct(getProductFromKeyboard());
				return;
			}
		}
		cout << "No such a dealer. " << endl;
	}
	else
		cout << "No dealers in the system." << endl;
}

void addFeedbackToDealer(TradeSystem * mySystem) {
	if (!mySystem->getUsers().empty()) {
		vector<User *> users = mySystem->getUsers();
		char buyersName[SIZE_NAME];
		cout << "Enter buyer's name: ";
		strcpy(buyersName, getStringFromKeyboard(SIZE_NAME));
		for (int i = 0; i < users.size(); i++) {
			if (strcmp(typeid(*users[i]).name(), typeid(Dealer).name()) != 0  && strcmp((users[i])->getName(), buyersName) == 0) { // buyer or buyer/dealer
				char dealerName[SIZE_NAME];
				cout << "Enter dealer's name: ";
				strcpy(dealerName, getStringFromKeyboard(SIZE_NAME));

				if (strcmp(buyersName, dealerName) == 0) {
					cout << "Can't give a feedback to yourself. " << endl;
					return;
				}

				for (int j = 0; j < users.size(); j++) {
					if (strcmp(typeid(*users[j]).name(), typeid(Buyer).name()) != 0 && strcmp((users[j])->getName(), dealerName) == 0) { // dealer or buyer/dealer
						vector<User *> buyers = (dynamic_cast<Dealer*>(users[j]))->getBuyers();
						for (int h = 0; h < buyers.size(); h++) {
							if (strcmp((buyers[h])->getName(), buyersName) == 0) {
								(dynamic_cast<Dealer*>(users[j]))->addFeedback(*getFeedbackFromKeyboard(buyersName));
								return;
							}
						}
						cout << (users[i])->getName() << " didn't but anything yet from " << (users[j])->getName() << endl;
						return;
					}
				}
				cout << "No such a dealer. " << endl;
				return;
			}
		}
		cout << "No such a buyer. " << endl;
		return;
	}
	else
		cout << "No users in the system. " << endl;
}

void addProductToBuyersBasket(TradeSystem * mySystem) {
	if (!mySystem->getUsers().empty()) {
		vector<User *> users = mySystem->getUsers();
		char buyersName[SIZE_NAME];
		cout << "Enter buyer's name: ";
		strcpy(buyersName, getStringFromKeyboard(SIZE_NAME));

		for (int i = 0; i < users.size(); i++) {
			if (strcmp(typeid(*users[i]).name(), typeid(Dealer).name()) != 0 && strcmp((users[i])->getName(), buyersName) == 0) { // buyer or buyer/dealer
				int productId;
				cout << "Enter product's id: ";
				cin >> productId;
				cin.ignore(256, '\n');

				for (int j = 0; j < users.size(); j++) {
					if (strcmp(typeid(*users[j]).name(), typeid(Dealer).name()) == 0 ||
						strcmp(typeid(*users[j]).name(), typeid(BuyerDealer).name()) == 0) {
						vector<Product *> products = (dynamic_cast<Dealer *>(users[j]))->getProducts();
						for (int h = 0; h < products.size(); h++) {
							if (productId == (products[h])->getProductId()) {
								if (i == j)
									cout << "Can't buy from yourself. " << endl;
								else
									(dynamic_cast<Buyer*>(users[i]))->addProductToBasket(products[h]);
								return;
							}
						}
					}
				}
				cout << "No product with such product's id. " << endl;
				return;
			}
		}
		cout << "No such a buyer. " << endl;
		return;
	}
	cout << "No users in the system. " << endl;
}

void printAllBuyers(TradeSystem * mySystem, bool bdPrint) {
	cout << "/" << setfill('*') << setw(50) << right << " BUYERS " << setw(50) << " /" << setfill(' ') << endl;
	if (!mySystem->getUsers().empty()) {
		cout << left << setw(20) << "Name:" << setw(30) << "Adress: " << endl;
		cout << setfill('-') << setw(100) << "-" << endl;
		for (int i = 0; i < mySystem->getUsers().size(); i++) {
			if (strcmp(typeid(*mySystem->getUsers()[i]).name(), typeid(Buyer).name()) == 0 ||
				( bdPrint && strcmp(typeid(*mySystem->getUsers()[i]).name(), typeid(BuyerDealer).name()) == 0 ))
					cout << *( dynamic_cast<Buyer*>(mySystem->getUsers()[i]) );
		}
	}
	cout << "/" << setfill('*') << setw(54) << right << " END OF BUYERS " << setw(46) << " /" << setfill(' ') << endl;
}
void printAllDealers(TradeSystem * mySystem, bool bdPrint) {
	cout << "/" << setfill('*') << setw(51) << right << " DEALERS " << setw(49) << " /" << setfill(' ') << endl;
	if (!mySystem->getUsers().empty()) {
		cout << left << setw(20) << "Name:" << setw(30) << "Adress: " << endl;
		cout << setfill('-') << setw(100) << "-" << endl;
		for (int i = 0; i < mySystem->getUsers().size(); i++) {
			if (strcmp(typeid(*mySystem->getUsers()[i]).name(), typeid(Dealer).name()) == 0 ||
				(bdPrint && strcmp(typeid(*mySystem->getUsers()[i]).name(), typeid(BuyerDealer).name()) == 0 )) {
				cout << *(dynamic_cast<Dealer*>(mySystem->getUsers()[i]));
			}
		}
	}
	cout << "/" << setfill('*') << setw(55) << right << " END OF DEALERS " << setw(45) << " /" << setfill(' ') << endl;
}
void printAllBuyerDealers(TradeSystem * mySystem) {
	cout << "/" << setfill('*') << setw(49) << right << " BUYER-DEALERS " << setw(49) << " /" << setfill(' ') << endl;
	if (!mySystem->getUsers().empty()) {
		cout << left << setw(20) << "Name:" << setw(30) << "Adress: " << endl;
		cout << setfill('-') << setw(100) << "-" << endl;
		for (int i = 0; i < mySystem->getUsers().size(); i++) {
			if ( strcmp(typeid(*mySystem->getUsers()[i]).name(), typeid(BuyerDealer).name()) == 0) {
				cout << *(dynamic_cast<BuyerDealer*>(mySystem->getUsers()[i]));
			}
		}
	}
	cout << "/" << setfill('*') << setw(52) << right << " END OF BUYER_DEALERS " << setw(46) << " /" << setfill(' ') << endl;
}

void printCertainClass(TradeSystem * mySystem) {
	int menuPrint = 0;

	cout << " 1 - To print only the buyers " << endl;
	cout << " 2 - To print only the dealers " << endl;
	cout << " 3 - To print only the buyers-dealers " << endl;
	cout << " 4 - To print all the buyers and buyers-dealers " << endl;
	cout << " 5 - To print all the dealers and buyers-dealers " << endl;
	cin >> menuPrint;

	switch (menuPrint) {
		case 1:printAllBuyers(mySystem, false); break;
		case 2:printAllDealers(mySystem, false); break;
		case 3:printAllBuyerDealers(mySystem); break;
		case 4:printAllBuyers(mySystem, true); break;
		case 5:printAllDealers(mySystem, true); break;
		default: break;
	}
}

void printSearchedProduct(TradeSystem * mySystem) {
	if (!mySystem->getUsers().empty()) {
		char productName[SIZE_NAME];
		cout << "Enter product's name: ";
		strcpy(productName, getStringFromKeyboard(SIZE_NAME));

		cout << left << setw(20) << "Name: " << "Price:  " << "Category:   " << "Id: " << endl;
		for (int i = 0; i < mySystem->getUsers().size(); i++) {
			if (strcmp(typeid(*mySystem->getUsers()[i]).name(), typeid(Dealer).name()) == 0 ||
				strcmp(typeid(*mySystem->getUsers()[i]).name(), typeid(BuyerDealer).name()) == 0) {
				if (!dynamic_cast<Dealer *>(mySystem->getUsers()[i])->getProducts().empty()) {
					vector<Product *> products = (dynamic_cast<Dealer *>(mySystem->getUsers()[i]))->getProducts();
					for (int j = 0; j < (dynamic_cast<Dealer *>(mySystem->getUsers()[i]))->getProducts().size(); j++) {
						if (strcmp(productName, (products[j])->getName()) == 0)
							cout << left << setw(20) << *products[j] << endl;
					}
				}
			}
		}
		cout << "No resaults." << endl;
		return;
	}
	else
		cout << "No products in the system. " << endl;
}

void checkOperators(TradeSystem * mySystem) {
	if (!mySystem->getUsers().empty()) {
		cout << "Enter the first buyer's name " << endl;
		char buyer1[SIZE_NAME];
		strcpy(buyer1, getStringFromKeyboard(SIZE_NAME));

		vector<User *> users = mySystem->getUsers();
		for (int i = 0; i < users.size(); i++) {
			if (strcmp(typeid(*users[i]).name(), typeid(Dealer).name()) != 0 && strcmp(buyer1, (users[i])->getName()))
			{
				cout << "Enter the second buyer's name " << endl;
				char buyer2[SIZE_NAME];
				strcpy(buyer2, getStringFromKeyboard(SIZE_NAME));
				for (int j = 0; j < users.size(); j++) {
					if (i != j && strcmp(typeid(*users[j]).name(), typeid(Dealer).name()) != 0 && strcmp(buyer2, (users[j])->getName()))
					{
						if (*(dynamic_cast<Buyer*>(users[i])) > *(dynamic_cast<Buyer*>(users[j]))) {
							cout << (users[i])->getName() << " > " << (users[j])->getName() << endl;
							return;
						}
						else if (*(dynamic_cast<Buyer*>(users[i])) < *(dynamic_cast<Buyer*>(users[j]))) {
							cout << (users[i])->getName() << " < " << (users[j])->getName() << endl;
							return;
						}
						else {
							cout << (users[j])->getName() << " == " << (users[i])->getName() << endl;
							return;
						}
					}
				}
				cout << "No such a buyer. " << endl;
				return;
			}
		}
		cout << "No such a buyer. " << endl;
		return;
	}
	else
		cout << "No buyers in the system. " << endl;
}