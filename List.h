#include "Node.h"

class LineList {

public:
	Line* Head;
	Line* Tail;

	Line* CategoryList;

	LineList();

	~LineList();

	void createLine(string name);
	void printLine();

};

//-----------------------------

class CategoryList {

public:
	Category* HeadC;
	Category* TailC;

	Category* ProductList;

	CategoryList();

	~CategoryList();

	void createCategory(string name, string Cname);
	void printCategory(string name);

};

//-----------------------------

class ProductList {

public:
	Product* HeadP;
	Product* TailP;

	ProductList();

	~ProductList();

	void createProduct(string Cname, string Pname, string date, double price, int quan);
	void printProduct(string name);
	void printProductChoose(string pro);
	Product* ProductList::seach_Product(string search);
	void increase_Amount(Product* found);
	void decrease_Amount(Product* found);
	void remove_product(string remove);
	void readproducts();

};

//-----------------------------

class MyCart {

public:
	Cart* HeadCart;
	Cart* TailCart;

	MyCart();

	~MyCart();

	void EmptyCart();
	void AddtoCart(string pro, string nodeD, double nodeP, int nodeQ);
	void printCart();
	Cart* search_Cart(string search);
	void remove(string name);


};

//-----------------------------

class ReportList {

public:
	Report* HeadR;
	Report* TailR;

	ReportList();

	~ReportList();

	void AddtoReport(string pro, string nodeD, double nodeP, int nodeQ);
	void printReport();
	Report* search_Report(string find);
	bool search_ReportBool(string find);
	void reportRemove(string name);
	void increaseAmount(Report* found);

};

//-----------------------------

class ReturnsList {

public:
	Return* HeadRet;
	Return* TailRet;

	ReturnsList();

	~ReturnsList();

	void AddtoReturns(string pro, string nodeD, double nodeP, int nodeQ);
	void printReturns();
	Return* search_Returns(string find);
	bool search_ReturnsBool(string find);
	void returnsRemove(string name);
	void increaseAmountReturned(Return* found);

};

//-----------------------------

class MyCustomers {

public:
	Customer* HeadCustomer;
	Customer* TailCustomer;

	MyCustomers();

	~MyCustomers();

	void add_Customer(string user_name, string user_add, int user_id, double user_points);
	void print_Customers();
	Customer* find_Customer(string user_name);

};


