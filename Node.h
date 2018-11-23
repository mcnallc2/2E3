#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Line {

private:

	string Name;
	Line* Next;
	Line* Prev;
	Line* Nested1;

public:

	Line(string name);

	string getName();

	Line* getNext();

	void setNext(Line* next);

	Line* getPrev();

	void setPrev(Line* prev);

	Line* getNested1();

	void setNested1(Line* nested1);
};

//-------------------------------

class Category {

private:

	string Lin;
	string CName;
	Category* NextC;
	Category* PrevC;
	Category* Nested2;

public:

	Category(string lin, string Cname);

	string getNameLin();

	string getNameC();

	Category* getNextC();

	void setNextC(Category* nextC);

	Category* getPrevC();

	void setPrevC(Category* prevC);

	Category* getNested2();

	void setNested2(Category* nested2);
};

//-----------------------------

class Product {

private:

	string Cate;
	string PName;
	string BBDate;
	double Price;
	int Quan;
	Product* NextP;

public:

	Product(string cate, string Pname, string date, double price, int quan);

	string getNameCate();

	string getNameP();

	string getBBDate();

	double getPrice();

	int getQuan();

	Product* getNextP();

	void setNextP(Product* nextP);
};

//-----------------------------

class Cart {

private:

	string Node;
	string NodeD;
	double NodeP;
	int NodeQ;
	Cart* NextNode;

public:

	Cart(string node, string nodeD, double nodeP, int nodeQ);

	string getNameN();

	string getD();

	double getP();

	int getQ();

	Cart* getNextN();

	void setNextN(Cart* nextP);
};

//-----------------------------

class Report {

private:

	string R_Name;
	string R_Date;
	double R_Price;
	int R_Quan;
	Report* NextR;

public:

	Report(string r_name, string r_date, double r_price, int r_quan);

	string getRN();

	string getRD();

	double getRP();

	int getRQ();

	Report* getNextR();

	void setNextR(Report* nextR);
};

//-----------------------------

class Return {

private:

	string Ret_Name;
	string Ret_Date;
	double Ret_Price;
	int Ret_Quan;
	Return* NextRet;

public:

	Return(string ret_name, string ret_date, double ret_price, int ret_quan);

	string getRetN();

	string getRetD();

	double getRetP();

	int getRetQ();

	Return* getNextRet();

	void setNextRet(Return* nextRet);
};

//-----------------------------

class Customer {

private:

	string User_Name;
	string User_Add;
	int User_ID;
	double User_Points;
	Customer* Next_User;

public:

	Customer(string user_name, string user_add, int user_id, double user_points);

	string getUser();

	string getAdd();

	int getID();

	double getPoints();

	Customer* getNextUser();

	void setNextUser(Customer* next_user);
};
