#include "List.h"

LineList::LineList() {

	Head = NULL;
	Tail = NULL;
}

LineList::~LineList() {

	Line* curr = Head;
	Line* temp;

	while (curr != NULL) {
		temp = curr;
		curr = curr->getNext();
		delete temp;
	}
	cout << "\nLines deconstructed\n";
}

void LineList::createLine(string name) {

	Line* newNode = new Line(name);
	newNode->setNested1(CategoryList);

	if (Head == NULL) {
		//list was empty
		Head = Tail = newNode;
	}
	else {
		Tail->setNext(newNode);
		Tail = newNode;
		Tail->setNext(NULL);
	}
}

void LineList::printLine() {

	if (Head != NULL) {
		Line* curr;
		curr = Head;
		while (curr != NULL) {
			cout << "\n----------------------\n";
			cout << curr->getName() << "     \n";
			cout << "----------------------\n";
			curr = curr->getNext();
		}
		cout << endl;
	}
	else {
		cout << "No Lines!\n\n";
	}
}


//-----------------------------


CategoryList::CategoryList() {

	HeadC = NULL;
	TailC = NULL;
}

CategoryList::~CategoryList() {

	Category* curr = HeadC;
	Category* temp;

	while (curr != NULL) {
		temp = curr;
		curr = curr->getNextC();
		delete temp;
	}
	cout << "\nCategories deconstructed\n";
}

void CategoryList::createCategory(string lin, string Cname) {

	Category* newNode = new Category(lin, Cname);
	newNode->setNested2(ProductList);

	if (HeadC == NULL) {
		//list was empty
		HeadC = TailC = newNode;
	}
	else {
		TailC->setNextC(newNode);
		TailC = newNode;
		TailC->setNextC(NULL);
	}
}

void CategoryList::printCategory(string lin) {

	if (HeadC != NULL) {
		Category* curr;
		curr = HeadC;
		while (curr != NULL) {
			if (curr->getNameLin() == lin) {
				cout << "\n----------------------\n";
				cout << curr->getNameC() << "     \n";
				cout << "----------------------\n";
			}
			curr = curr->getNextC();
		}
		cout << endl;
	}
	else {
		cout << "No Categories!\n\n";
	}
}


//-----------------------------


ProductList::ProductList() {

	HeadP = NULL;
	TailP = NULL;
}

ProductList::~ProductList() {

	Product* curr = HeadP;
	Product* temp;

	while (curr != NULL) {
		temp = curr;
		curr = curr->getNextP();
		delete temp;
	}
	cout << "\nProducts deconstructed\n";
}

void ProductList::createProduct(string cate, string Pname, string date, double price, int quan) {

	Product* newNode = new Product(cate, Pname, date, price, quan);

	if (HeadP == NULL) {
		//list was empty
		HeadP = TailP = newNode;
	}
	else {
		TailP->setNextP(newNode);
		TailP = newNode;
		TailP->setNextP(NULL);
	}
}

void ProductList::printProduct(string cate) {

	if (HeadP != NULL) {
		Product* curr;
		curr = HeadP;
		while (curr != NULL) {
			if (curr->getNameCate() == cate) {
				cout << "\n----------------------\n";
				cout << curr->getNameP() << "     \n";
				cout << "----------------------\n";
			}
			curr = curr->getNextP();
		}
		cout << endl;
	}
	else {
		cout << "No Categories!\n\n";
	}
}

void ProductList::readproducts() {

	ofstream saveData;
	saveData.open("Stock.txt");

	saveData << "\n--------------------------------";
	saveData << "\n------- Updated Products -------\n";

	if (HeadP != NULL) {
		Product* curr;
		curr = HeadP;
		while (curr != NULL) {

			saveData << "\n----------------------\n";
			saveData << curr->getNameP() << "     \n";
			saveData << "BBD: ";
			saveData << curr->getBBDate() << "     \n";
			saveData << "€ ";
			saveData << curr->getPrice() << "     \n";
			saveData << curr->getQuan() << " left\n";
			saveData << "----------------------\n";

			curr = curr->getNextP();
		}
		cout << endl;
	}
	else {
		saveData << "No Products!\n\n";
		saveData << "--------------------------------\n";
	}
	saveData.close();
}


void ProductList::printProductChoose(string pro) {

	if (HeadP != NULL) {
		Product* curr;
		curr = HeadP;
		while (curr != NULL) {
			if (curr->getNameP() == pro) {
				cout << "\n----------------------\n";
				cout << curr->getNameP() << "     \n";
				cout << "BBD: ";
				cout << curr->getBBDate() << "     \n";
				cout << "€ ";
				cout << curr->getPrice() << "     \n";
				cout << curr->getQuan() << " left\n";
				cout << "----------------------\n";
			}
			curr = curr->getNextP();
		}
		cout << endl;
	}
	else {
		cout << "No such Product!\n\n";
	}
}

Product* ProductList::seach_Product(string search) {

	Product* curr = HeadP;

	while (curr != NULL) {
		if (curr->getNameP() == search) {
			return curr;
		}
		curr = curr->getNextP();
	}
	return NULL;
}

void ProductList::decrease_Amount(Product* found) {

	string same_c_name;
	string same_name;
	string same_date;
	double same_price;
	int decrease;

	same_c_name = found->getNameCate();
	same_name = found->getNameP();
	same_date = found->getBBDate();
	same_price = found->getPrice();
	decrease = (found->getQuan() - 1);
	remove_product(same_name);
	createProduct(same_c_name, same_name, same_date, same_price, decrease);

}

void ProductList::increase_Amount(Product* found) {

	string same_c_name;
	string same_name;
	string same_date;
	double same_price;
	int increase;

	same_c_name = found->getNameCate();
	same_name = found->getNameP();
	same_date = found->getBBDate();
	same_price = found->getPrice();
	increase = (found->getQuan() + 1);

	remove_product(same_name);
	createProduct(same_c_name, same_name, same_date, same_price, increase);

}

void ProductList::remove_product(string name) {

	Product* curr = HeadP;
	Product* p = NULL;
	Product* ha = NULL;

	if (seach_Product(name) != NULL) {

		if (seach_Product(name) == HeadP) {
			HeadP = HeadP->getNextP();
			delete curr;
		}

		else {
			while (name != curr->getNextP()->getNameP()) {
				curr = curr->getNextP();
			}

			p = curr->getNextP();

			if (p != TailP) {
				ha = curr->getNextP();
				curr->setNextP(p->getNextP());
				delete ha;
			}

			if (p == TailP) {
				ha = TailP;
				TailP = curr;
				curr->setNextP(NULL);
				delete ha;
			}
		}
	}

	else
		cout << "\nProduct not in Cart\n";
}


//-----------------------------


MyCart::MyCart() {

	HeadCart = NULL;
	TailCart = NULL;
}

MyCart::~MyCart() {

	Cart* curr = HeadCart;
	Cart* temp;

	while (curr != NULL) {
		temp = curr;
		curr = curr->getNextN();
		delete temp;
	}
	cout << "\nCart deconstructed\n";
}

void MyCart::EmptyCart() {

	Cart* curr = HeadCart;
	Cart* temp;

	while (curr != NULL) {
		temp = curr;
		curr = curr->getNextN();
		delete temp;
	}
}

void MyCart::AddtoCart(string pro, string nodeD, double nodeP, int nodeQ) {

	Cart* newNode = new Cart(pro, nodeD, nodeP, nodeQ);

	if (HeadCart == NULL) {
		//list was empty
		HeadCart = TailCart = newNode;
	}
	else {
		TailCart->setNextN(newNode);
		TailCart = newNode;
		TailCart->setNextN(NULL);
	}
}

void MyCart::printCart() {

	cout << "\nYOUR SHOPPING CART\n";

	if (HeadCart != NULL) {
		Cart* curr;
		curr = HeadCart;
		while (curr != NULL) {
			cout << "\n----------------------\n";
			cout << curr->getNameN() << "     \n";
			cout << "BBD: ";
			cout << curr->getD() << "     \n";
			cout << "€ ";
			cout << curr->getP() << "     \n";
			cout << "----------------------\n";

			curr = curr->getNextN();
		}
		cout << endl;
	}
	else {
		cout << "Empty Cart!\n\n";
	}
}

Cart* MyCart::search_Cart(string search) {

	Cart* curr = HeadCart;

	while (curr != NULL) {
		if (curr->getNameN() == search) {
			return curr;
		}
		curr = curr->getNextN();
	}
	return NULL;
}

void MyCart::remove(string name) {

	Cart* curr = HeadCart;
	Cart* p = NULL;
	Cart* ha = NULL;

	if (search_Cart(name) != NULL) {

		if (search_Cart(name) == HeadCart) {
			HeadCart = HeadCart->getNextN();
			delete curr;
		}

		else {
			while (name != curr->getNextN()->getNameN()) {
				curr = curr->getNextN();
			}

			p = curr->getNextN();

			if (p != TailCart) {
				ha = curr->getNextN();
				curr->setNextN(p->getNextN());
				delete ha;
			}

			if (p == TailCart) {
				ha = TailCart;
				TailCart = curr;
				curr->setNextN(NULL);
				delete ha;
			}
		}
	}

	else
		cout << "\nProduct not in Cart\n";
}


//-----------------------------

ReportList::ReportList() {

	HeadR = NULL;
	TailR = NULL;
}

ReportList::~ReportList() {

	Report* curr = HeadR;
	Report* temp;

	while (curr != NULL) {
		temp = curr;
		curr = curr->getNextR();
		delete temp;
	}
	cout << "\nReport deconstructed\n";
}

void ReportList::AddtoReport(string r_name, string r_date, double r_price, int r_quan) {

	Report* newNode = new Report(r_name, r_date, r_price, r_quan);

	if (HeadR == NULL) {
		//list was empty
		HeadR = TailR = newNode;
	}
	else {
		TailR->setNextR(newNode);
		TailR = newNode;
		TailR->setNextR(NULL);
	}
}

void ReportList::printReport() {

	ofstream saveData;
	saveData.open("Report.txt");

	cout << "\n----------------------------------------";
	cout << "\n---------------- Report ----------------\n\n";

	if (HeadR != NULL) {
		Report* curr;
		curr = HeadR;
		while (curr != NULL) {
			cout << "\n----------------------\n";
			cout << curr->getRN() << endl;
			cout << "€ " << curr->getRP() << endl;
			cout << curr->getRQ() << " products sold\n";
			cout << "----------------------\n";

			curr = curr->getNextR();
		}
		cout << endl;
	}
	else {
		cout << "No Sales to Report...\n\n";
	}

	saveData << "\n----------------------------------------";
	saveData << "\n---------------- Report ----------------\n";

	if (HeadR != NULL) {
		Report* curr;
		curr = HeadR;
		while (curr != NULL) {
			saveData << "\n----------------------\n";
			saveData << curr->getRN() << endl;
			saveData << "€ " << curr->getRP() << endl;
			saveData << curr->getRQ() << " products sold\n";
			saveData << "----------------------\n";

			curr = curr->getNextR();
		}
		saveData << endl;
	}
	else {
		saveData << "No Sales to Report...\n\n";
	}
	saveData << "\n----------------------------------------";
	saveData << "\n----------------------------------------\n\n";
	saveData.close();
}

Report* ReportList::search_Report(string find) {

	Report* curr = HeadR;

	while (curr != NULL) {
		if (curr->getRN() == find) {
			return curr;
		}
		curr = curr->getNextR();
	}
	return NULL;
}

bool ReportList::search_ReportBool(string find) {

	Report* curr = HeadR;

	while (curr != NULL) {
		if (curr->getRN() == find) {
			return true;
		}
		curr = curr->getNextR();
	}
	return false;
}

void ReportList::reportRemove(string name) {

	Report* curr = HeadR;
	Report* p = NULL;
	Report* ha = NULL;

	if (search_Report(name) != NULL) {

		if (search_Report(name) == HeadR) {
			HeadR = HeadR->getNextR();
			delete curr;
		}

		else {
			while (name != curr->getNextR()->getRN()) {
				curr = curr->getNextR();
			}

			p = curr->getNextR();

			if (p != TailR) {
				ha = curr->getNextR();
				curr->setNextR(p->getNextR());
				delete ha;
			}

			if (p == TailR) {
				ha = TailR;
				TailR = curr;
				curr->setNextR(NULL);
				delete ha;
			}
		}
	}

	else
		cout << "\nError\n";
}

void ReportList::increaseAmount(Report* found) {

	string same_name;
	string same_date;
	double same_price;
	int increase;

	same_name = found->getRN();
	same_date = found->getRD();
	same_price = found->getRP();
	increase = (found->getRQ() + 1);

	reportRemove(same_name);
	AddtoReport(same_name, same_date, same_price, increase);

}


//-----------------------------

ReturnsList::ReturnsList() {

	HeadRet = NULL;
	TailRet = NULL;
}

ReturnsList::~ReturnsList() {

	Return* curr = HeadRet;
	Return* temp;

	while (curr != NULL) {
		temp = curr;
		curr = curr->getNextRet();
		delete temp;
	}
	cout << "\nReturns deconstructed\n";
}

void ReturnsList::AddtoReturns(string ret_name, string ret_date, double ret_price, int ret_quan) {

	Return* newNode = new Return(ret_name, ret_date, ret_price, ret_quan);

	if (HeadRet == NULL) {
		//list was empty
		HeadRet = TailRet = newNode;
	}
	else {
		TailRet->setNextRet(newNode);
		TailRet = newNode;
		TailRet->setNextRet(NULL);
	}
}

void ReturnsList::printReturns() {

	ofstream saveData;
	saveData.open("Returns.txt");

	cout << "\n----------- Returns -----------\n\n";

	if (HeadRet != NULL) {
		Return* curr;
		curr = HeadRet;
		while (curr != NULL) {
			cout << "\n----------------------\n";
			cout << curr->getRetN() << endl;
			cout << "€ " << curr->getRetP() << endl;
			cout << curr->getRetQ() << " products returned\n";
			cout << "----------------------\n";

			curr = curr->getNextRet();
		}
		cout << endl;
	}
	else {
		cout << "No Returns to Report...\n\n";
	}
	cout << "\n----------------------------------------";
	cout << "\n----------------------------------------\n\n";

	saveData << "\n----------------------------------------";
	saveData << "\n--------------- Returns ----------------\n";


	if (HeadRet != NULL) {
		Return* curr;
		curr = HeadRet;
		while (curr != NULL) {
			saveData << "\n----------------------\n";
			saveData << curr->getRetN() << endl;
			saveData << "€ " << curr->getRetP() << endl;
			saveData << curr->getRetQ() << " products returned\n";
			saveData << "----------------------\n";

			curr = curr->getNextRet();
		}
		saveData << endl;
	}
	else {
		saveData << "No Returns to Report...\n\n";
	}
	saveData << "\n----------------------------------------";
	saveData << "\n----------------------------------------\n\n";
	saveData.close();
}

Return* ReturnsList::search_Returns(string find) {

	Return* curr = HeadRet;

	while (curr != NULL) {
		if (curr->getRetN() == find) {
			return curr;
		}
		curr = curr->getNextRet();
	}
	return NULL;
}

bool ReturnsList::search_ReturnsBool(string find) {

	Return* curr = HeadRet;

	while (curr != NULL) {
		if (curr->getRetN() == find) {
			return true;
		}
		curr = curr->getNextRet();
	}
	return false;
}

void ReturnsList::returnsRemove(string name) {

	Return* curr = HeadRet;
	Return* p = NULL;
	Return* ha = NULL;

	if (search_Returns(name) != NULL) {

		if (search_Returns(name) == HeadRet) {
			HeadRet = HeadRet->getNextRet();
			delete curr;
		}

		else {
			while (name != curr->getNextRet()->getRetN()) {
				curr = curr->getNextRet();
			}

			p = curr->getNextRet();

			if (p != TailRet) {
				ha = curr->getNextRet();
				curr->setNextRet(p->getNextRet());
				delete ha;
			}

			if (p == TailRet) {
				ha = TailRet;
				TailRet = curr;
				curr->setNextRet(NULL);
				delete ha;
			}
		}
	}

	else
		cout << "\nError\n";
}

void ReturnsList::increaseAmountReturned(Return* found) {

	string same_name;
	string same_date;
	double same_price;
	int increase;

	same_name = found->getRetN();
	same_date = found->getRetD();
	same_price = found->getRetP();
	increase = (found->getRetQ() + 1);

	returnsRemove(same_name);
	AddtoReturns(same_name, same_date, same_price, increase);

}


//-----------------------------

MyCustomers::MyCustomers() {

	HeadCustomer = NULL;
	TailCustomer = NULL;
}

MyCustomers::~MyCustomers() {

	Customer* curr = HeadCustomer;
	Customer* temp;

	while (curr != NULL) {
		temp = curr;
		curr = curr->getNextUser();
		delete temp;
	}
	cout << "\nCustomers deconstructed\n";
}

void MyCustomers::add_Customer(string user_name, string user_add, int user_id, double user_points) {

	Customer* newNode = new Customer(user_name, user_add, user_id, user_points);

	if (HeadCustomer == NULL) {
		//list was empty
		HeadCustomer = TailCustomer = newNode;
	}
	else {
		TailCustomer->setNextUser(newNode);
		TailCustomer = newNode;
		TailCustomer->setNextUser(NULL);
	}
}

void MyCustomers::print_Customers() {

	if (HeadCustomer != NULL) {
		Customer* curr;
		curr = HeadCustomer;
		while (curr != NULL) {
			cout << "\n----------------------\n";
			cout << curr->getUser() << "     \n";
			cout << curr->getAdd() << "     \n";
			cout << curr->getID() << "     \n";
			cout << curr->getPoints() << "     \n";
			cout << "----------------------\n";

			curr = curr->getNextUser();
		}
		cout << endl;
	}
	else {
		cout << "No Customers!\n\n";
	}
}

Customer* MyCustomers::find_Customer(string user_name) {

	Customer* curr = HeadCustomer;
	while (curr != NULL) {

		if (curr->getUser() == user_name) {
			return curr;
		}
		curr = curr->getNextUser();
	}
	return NULL;
}