#include "Node.h"

Line::Line(string name) {
	Name = name;
}

string Line::getName() {
	return Name;
}

Line* Line::getNext() {
	return Next;
}

void Line::setNext(Line* next) {
	Next = next;
}

Line* Line::getPrev() {
	return Prev;
}

void Line::setPrev(Line* prev) {
	Prev = prev;
}

Line* Line::getNested1() {
	return Nested1;
}

void Line::setNested1(Line* nested1) {
	Nested1 = nested1;
}

//-------------------------

Category::Category(string lin, string Cname) {
	Lin = lin;
	CName = Cname;
}

string Category::getNameLin() {
	return Lin;
}

string Category::getNameC() {
	return CName;
}

Category* Category::getNextC() {
	return NextC;
}

void Category::setNextC(Category* nextC) {
	NextC = nextC;
}

Category* Category::getPrevC() {
	return PrevC;
}

void Category::setPrevC(Category* prevC) {
	PrevC = prevC;
}

Category* Category::getNested2() {
	return Nested2;
}

void Category::setNested2(Category* nested2) {
	Nested2 = nested2;
}

//---------------------------

Product::Product(string cate, string Pname, string date, double price, int quan) {
	Cate = cate;
	PName = Pname;
	BBDate = date;
	Price = price;
	Quan = quan;
}

string Product::getNameCate() {
	return Cate;
}

string Product::getNameP() {
	return PName;
}

string Product::getBBDate() {
	return BBDate;
}

double Product::getPrice() {
	return Price;
}

int Product::getQuan() {
	return Quan;
}

Product* Product::getNextP() {
	return NextP;
}

void Product::setNextP(Product* nextP) {
	NextP = nextP;
}

//---------------------------

Cart::Cart(string node, string nodeD, double nodeP, int nodeQ) {

	Node = node;
	NodeD = nodeD;
	NodeP = nodeP;
	NodeQ = nodeQ;
}

string Cart::getNameN() {
	return Node;
}

string Cart::getD() {
	return NodeD;
}

double Cart::getP() {
	return NodeP;
}

int Cart::getQ() {
	return NodeQ;
}

Cart* Cart::getNextN() {
	return NextNode;
}

void Cart::setNextN(Cart* nextNode) {
	NextNode = nextNode;
}

//---------------------------

Report::Report(string r_name, string r_date, double r_price, int r_quan) {

	R_Name = r_name;
	R_Date = r_date;
	R_Price = r_price;
	R_Quan = r_quan;
}

string Report::getRN() {
	return R_Name;
}

string Report::getRD() {
	return R_Date;
}

double Report::getRP() {
	return R_Price;
}

int Report::getRQ() {
	return R_Quan;
}

Report* Report::getNextR() {
	return NextR;
}

void Report::setNextR(Report* nextR) {
	NextR = nextR;
}


//---------------------------

Return::Return(string ret_name, string ret_date, double ret_price, int ret_quan) {

	Ret_Name = ret_name;
	Ret_Date = ret_date;
	Ret_Price = ret_price;
	Ret_Quan = ret_quan;
}

string Return::getRetN() {
	return Ret_Name;
}

string Return::getRetD() {
	return Ret_Date;
}

double Return::getRetP() {
	return Ret_Price;
}

int Return::getRetQ() {
	return Ret_Quan;
}

Return* Return::getNextRet() {
	return NextRet;
}

void Return::setNextRet(Return* nextRet) {
	NextRet = nextRet;
}

//---------------------------

Customer::Customer(string user_name, string user_add, int user_id, double user_points) {

	User_Name = user_name;
	User_Add = user_add;
	User_ID = user_id;
	User_Points = user_points;
}

string Customer::getUser() {
	return User_Name;
}

string Customer::getAdd() {
	return User_Add;
}

int Customer::getID() {
	return User_ID;
}

double Customer::getPoints() {
	return User_Points;
}

Customer* Customer::getNextUser() {
	return Next_User;
}

void Customer::setNextUser(Customer* next_user) {
	Next_User = next_user;
}




