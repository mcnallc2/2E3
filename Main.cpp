#include "List.h"

void main() {

	cout << "Hi, welcome to McNoodles'\n\nPlease enter the data correctly,\nusing lowercase and underscores where appropriate.\n\n";
	cout << "Some user accounts already exist, and can be seen in the Users.txt file.\n\n";
	cout << "The updated stock will be shown in the corresponding file when the program ends.\nThe report and returns will be printed at the end of the program\n";
	cout << "and shown in their files when the program ends.\n\nThank you.\n\n\n";

	LineList a;
	CategoryList b;
	ProductList c;
	MyCart d;
	MyCustomers e;
	ReportList f;
	ReturnsList g;

	double Total = 0.0;
	double New_total = 0.0;
	double Report_total = 0.0;
	int Start_q = 1;
	char add, answer = 'Y', customer = 'y';

	ifstream takeData;
	ofstream saveData;
	takeData.open("List.txt");

	string L, C, P, D;
	double PR;
	int Q;
	bool i = true;

	while (i == true) {
		takeData >> L;
		if (L == "XXX") {
			break;
		}
		a.createLine(L);
		while (i == true) {
			takeData >> C;
			if (C == "XXX") {
				break;
			}
			b.createCategory(L, C);
			while (i == true) {
				takeData >> P;
				if (P == "XXX") {
					break;
				}
				takeData >> D;
				takeData >> PR;
				takeData >> Q;
				c.createProduct(C, P, D, PR, Q);
			}
		}
	}
	takeData.close();

	takeData.open("Users.txt");
	string user_name, new_user, user_add, new_add;
	int user_id, new_id = 1;
	double user_points, new_points = 0;

	while (i == true) {
		takeData >> user_name;
		if (user_name == "XXX") {
			break;
		}
		takeData >> user_add;
		takeData >> user_id;
		new_id++;
		takeData >> user_points;
		e.add_Customer(user_name, user_add, user_id, user_points);
	}
	takeData.close();
	//saveData.open("Users.txt");

	char report = 'Y';
	while (report == 'Y' || report == 'y') {

		//d.EmptyCart();
		Total = 0;
		New_total = 0;

		cout << "Are you an existing customer?\n(Y/N)\n";
		cin >> customer;

		if (customer == 'N' || customer == 'n') {
			cout << "To register enter a Name & Address (County) and your ID will be assigned (Lowercase)\n";
			cin >> new_user >> new_add;

			user_name = new_user;
			user_add = new_add;
			user_id = new_id;
			user_points = new_points;
			new_id++;

			cout << "\nSuccessfully Registered !!!\n" << "Your assigned ID: " << user_id << endl << endl;
			e.add_Customer(user_name, user_add, user_id, user_points);
			//saveData << user_name << " " << user_add << " " << user_id << " " << user_points << endl;
			//saveData.close();
		}
		else {
			cout << "Enter your User_Name (Lowercase)\n";
			cin >> user_name;
			bool exit = false;
			while (exit == false) {
				if (e.find_Customer(user_name) != NULL) {
					cout << "\nLogged In !!!\n\n";
					user_add = e.find_Customer(user_name)->getAdd();
					user_id = e.find_Customer(user_name)->getID();
					user_points = e.find_Customer(user_name)->getPoints();
					exit = true;
				}
				else {
					cout << "No such User_Name \nRe-enter your User_Name (Users.txt) \n";
					cin >> user_name;
				}
			}
		}
		char end = 'y';

		while (end == 'Y' || end == 'y') {

			cout << "Browse:\t\t'B'\n";
			cout << "Search:\t\t'S'\n";
			cout << "Returns:\t'R'\n";
			cout << "View Cart:\t'V'\n";
			cin >> answer;

			string lin, cate, pro;
			if (answer == 'b' || answer == 'B') {

				a.printLine();
				cout << "Choose a line!\n";
				cin >> lin;


				b.printCategory(lin);
				cout << "Choose a Category!\n";
				cin >> cate;

				c.printProduct(cate);
				cout << "Choose a Product!\n";
				cin >> pro;

				while (c.seach_Product(pro) == NULL) {
					cout << "Product does not exist. Please re-enter product name.\n";
					cin >> pro;
				}

				c.printProductChoose(pro);

				cout << "Would you like to Add to Cart\n(Y/N)\n";
				cin >> add;

				string p_name;
				string p_date;
				double p_price;
				int p_quan;
				if (add == 'y' || add == 'Y') {
					p_name = c.seach_Product(pro)->getNameP();
					p_date = c.seach_Product(pro)->getBBDate();
					p_price = c.seach_Product(pro)->getPrice();
					p_quan = c.seach_Product(pro)->getQuan();
					Total = Total + p_price;
					d.AddtoCart(p_name, p_date, p_price, p_quan);
					c.decrease_Amount(c.seach_Product(pro));
					if (f.search_ReportBool(p_name) == true) {
						f.increaseAmount(f.search_Report(p_name));
					}
					else {
						f.AddtoReport(p_name, p_date, p_price, Start_q);
					}

				}
			}

			if (answer == 's' || answer == 'S') {

				string search;
				cout << "Search ... ";
				cin >> search;

				while (c.seach_Product(search) == NULL) {
					cout << "Product does not exist. Please re-enter product name.\n";
					cin >> search;
				}
				c.printProductChoose(search);

				cout << "Would you like to Add to Cart\n(Y/N)\n";
				cin >> add;
				string p_name;
				string p_date;
				double p_price;
				int p_quan;
				if (add == 'y' || add == 'Y') {
					p_name = c.seach_Product(search)->getNameP();
					p_date = c.seach_Product(search)->getBBDate();
					p_price = c.seach_Product(search)->getPrice();
					p_quan = c.seach_Product(search)->getQuan();
					Total = Total + p_price;
					d.AddtoCart(p_name, p_date, p_price, p_quan);
					c.decrease_Amount(c.seach_Product(search));
					if (f.search_ReportBool(p_name)) {
						f.increaseAmount(f.search_Report(p_name));
					}
					else {
						f.AddtoReport(p_name, p_date, p_price, Start_q);
					}
				}
			}
			if (answer == 'r' || answer == 'R') {

				string retur;
				cout << "Enter name of product to be returned\n";
				cin >> retur;

				while (c.seach_Product(retur) == NULL) {
					cout << "Product does not exist. Try again\n";
					cin >> retur;
				}
				c.printProductChoose(retur);
				cout << "Are you sure you want to return product\n(Y/N)\n";
				cin >> add;
				string ret_name;
				string ret_date;
				double ret_price;
				int ret_quan;
				if (add == 'y' || add == 'Y') {
					ret_name = c.seach_Product(retur)->getNameP();
					ret_date = c.seach_Product(retur)->getBBDate();
					ret_price = c.seach_Product(retur)->getPrice();
					ret_quan = c.seach_Product(retur)->getQuan();

					if (g.search_ReturnsBool(ret_name)) {
						g.increaseAmountReturned(g.search_Returns(ret_name));
					}
					else {
						g.AddtoReturns(ret_name, ret_date, ret_price, Start_q);
					}
				}

			}

			if (answer == 'v' || answer == 'V') {

				d.printCart();
				char remove;
				string rid;

				cout << "Do you want to remove anthing from the Cart?\n(Y/N)\n";
				cin >> remove;

				while (remove == 'y' || remove == 'y') {
					cout << "Enter of name of product to remove\n";
					cin >> rid;
					Total = Total - c.seach_Product(rid)->getPrice();
					d.remove(rid);
					f.reportRemove(rid);
					c.increase_Amount(c.seach_Product(rid));
					d.printCart();
					cout << "Do you want to remove another?\n(Y/N)\n";
					cin >> remove;
				}
			}
			cout << "Do you want to continue shopping\n(Y/N)\n";
			cin >> end;
			char sure;
			if (end == 'N' || end == 'n') {
				d.printCart();
				char remove;
				string rid;

				cout << "Do you want to remove anthing from the Cart?\n(Y/N)\n";
				cin >> remove;

				while (remove == 'y' || remove == 'y') {
					cout << "Enter of name of product to remove\n";
					cin >> rid;
					Total = Total - c.seach_Product(rid)->getPrice();
					d.remove(rid);
					f.reportRemove(rid);
					c.increase_Amount(c.seach_Product(rid));
					d.printCart();
					cout << "Do you want to remove another?\n(Y/N)\n";
					cin >> remove;
				}
				cout << "Are you sure you want to Check_Out\n(Y/N)\n";
				cin >> sure;
				if (sure == 'N' || sure == 'n') {
					end = 'Y';
				}
			}
		}
		bool discount = false;
		if (Total >= 100) {
			cout << "\nYou spent €100 or more, you now recieve a 10% discount\n\n";
			Total = (Total / 10) * 9;
			discount = true;
		}

		int points_left, how_many = 0, new_user_points;
		char use_points;
		points_left = e.find_Customer(user_name)->getPoints();
		cout << "You have " << points_left << " points on your account.\n";
		cout << "Would you like to use them?\n(Y/N)\n";
		cin >> use_points;

		if (use_points == 'Y' || use_points == 'y') {
			cout << "How many points would you like to use?\n";
			cin >> how_many;
			while (how_many > user_points) {
				cout << "You do not have that many points try again.\n";
				cin >> how_many;
			}
			new_user_points = user_points - how_many;
			New_total = Total - (how_many / 10);
		}
		else {
			new_user_points = user_points;
			New_total = Total;
		}
		new_user_points = new_user_points + New_total;

		cout << "----------------------------------------\n";
		cout << "--------------YOUR RECIEPT--------------\n\n";

		cout << "Name\t" << user_name << endl;
		cout << "Address\t" << user_add << endl;
		cout << "ID:\t" << user_id << endl;
		cout << "Points\t" << user_points << endl;

		d.printCart();
		if (discount == true) {
			cout << "\nYou recieved the 10% discount!\n\n";
			discount = false;
		}
		cout << "Total:  € " << Total << endl << endl;
		cout << "You paid € " << New_total << endl << endl;
		cout << "You used " << how_many << " points" << endl;
		cout << "You are rewarded " << New_total << " points" << endl;
		cout << "You have " << new_user_points << " remaining\n";
		cout << "\nThank you for shopping with McNoodle's\n";
		cout << "----------------------------------------\n";
		cout << "----------------------------------------\n";

		cout << "\nDo you want to return to Log In Screen\n(Y/N)\n";
		cin >> report;

		Report_total = Report_total + Total;

		char sure;
		if (report == 'N' || report == 'n') {
			cout << "Are you sure you want to Exit Program\n(Y/N)\n";
			cin >> sure;
			if (sure == 'N' || sure == 'n') {
				report = 'Y';
			}
		}
	}

	f.printReport();
	cout << "Total Income = €" << Report_total << endl << endl;
	g.printReturns();

	c.readproducts();

	cin.get();
	cin.get();
}

// Find out how to empty the cart
// .........
