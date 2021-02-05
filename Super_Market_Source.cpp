#include"Super_Market.h"

void inputValidation(istream& cin) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << COLOR_RED << "Your input was wrong please try again!" << COLOR_RESET << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1050));
	system("cls");
}

void Date::setDay(int day) {
	this->day = day;
}
int Date::getDay() {
	return day;
}

void Date::setMonth(int month) {
	this->month = month;
}
int Date::getMonth() {
	return month;
}

void Date::setYear(int year) {
	this->year = year;
}
int Date::getYear() {
	return year;
}

ostream& operator << (ostream& out, const Date& attribute) {
	out << attribute.day << "/"
		<< attribute.month << "/"
		<< attribute.year << endl;
	return out;
};

/*ifstream& operator >> (ifstream& in, Date& attribute) {
	in >> attribute.day
		>> attribute.month
		>> attribute.year;
	return in;
}*/

void Product::setNumber(int number) {
	this->number = number;
};
int Product::getNumber() {
	return number;
};

void Product::setName(string name) {
	this->name = name;
};
string Product::getName() {
	return name;
};

void Product::setPrice(float price) {
	this->price = price;
};
float Product::getPrice() {
	return price;
};

void Product::setCount(int count) {
	this->count = count;
};
int Product::getCount() {
	return count;
};

void Product::Show() {
	cout << COLOR_CYAN << "Number:" << getNumber() << "   "
		<< "Name:" << getName() << "   "
		<< "Price:" << getPrice() << "   "
		<< "Count:" << getCount() << endl << endl;
}

void Product::setAll() {
	//Ask For Product Number
	do {
		cout << COLOR_CYAN << "Number:";
		int number;
		cin >> number;
		if (cin.fail() || number <= 0) inputValidation(cin);
		else {
			try {
				numberRepeatCheck(number);
			}
			catch (const char*) {
				cerr << COLOR_RED << "Your input is repetitive please try again!" << COLOR_RESET << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(3050));
				system("cls");
				continue;
			}
			setNumber(number);
			break;
		}
	} while (true);
	//Ask For Product Name
	do {
		cout << COLOR_CYAN << "Name:";
		string name;
		cin >> name;
		if (cin.fail()) inputValidation(cin);
		else {
			setName(name);
			break;
		}
	} while (true);
	//Ask For Product Price
	do {
		cout << "Price:";
		float price;
		cin >> price;
		if (cin.fail() || price <= 0)  inputValidation(cin);
		else {
			setPrice(price);
			break;
		}
	} while (true);
	//Ask For Product Count
	do {
		cout << "Count:";
		int count;
		cin >> count;
		if (cin.fail() || count <= 0)  inputValidation(cin);
		else {
			setCount(count);
			break;
		}
	} while (true);
}

ostream& operator << (ostream& out, const Product& attribute)
{
	out << attribute.number << "  "
		<< attribute.name << "  "
		<< attribute.price << "  "
		<< attribute.count << endl;

	return out;
}

ofstream& operator << (ofstream& out, Product& attribute) {
	out << attribute.number << "  "
		<< attribute.name << "  "
		<< attribute.price << "  "
		<< attribute.count << endl;
	return out;
}

ifstream& operator >> (ifstream& in, Product& attribute) {
	in >> attribute.number
		>> attribute.name
		>> attribute.price
		>> attribute.count
		;
	return in;
};

void writeInList(Product product) {
	string nameOfFile = "Product.dat";
	ofstream File("Product.dat", ios::app);
	File << product;
	File.close();
}

int countFileLine() {
	int n = 0;
	Product product;
	string nameOfFile = "Product.dat";
	ifstream File("Product.dat", ios::in);
	if (!File) {
		cerr << COLOR_RED << "Som thing went wrong please try again !" << endl;
		return n;
	}
	else {
		while (!File.eof())
		{
			Product product;
			File >> product;
			n++;
		}
		File.close();
		return n - 1;
	}
};

void readFromList() {
	if (countFileLine() == 0) cout << COLOR_RED << "The file is empty" << COLOR_RESET << endl;
	Product product;
	string nameOfFile = "Product.dat";
	ifstream File("Product.dat", ios::in);
	if (!File) {
		throw 1;
	}
	else {
		for (int i = 0; i < countFileLine(); i++)
		{
			Product product;
			File >> product;
			product.Show();
			//cout<<product<<endl;
		}
	}
	File.close();
}

void Find(int number) {
	if (number <= 0) throw "false";
	else {
		Product product;
		string nameOfFile = "Product.dat";
		ifstream File("Product.dat", ios::in);
		bool flag = 1;
		while (!File.eof())
		{
			Product product;
			File >> product;
			if (number == product.getNumber()) {
				product.Show();
				flag = 0;
				break;
			}
			else continue;
		}
		if (flag == 1) throw 1;
		File.close();
	}
};

void Edit(int number) {
	ifstream read, read1;
	ofstream write, write1;
	Product product, old, New, temp;
	bool flag = 1;

	string nameOfFile = "Product.dat";
	read.open("Product.dat", ios::in);
	ifstream File("Product.dat", ios::in);
	if (!File) {
		throw 1;
	}
	write.open("Temp.txt");

	while (!read.eof())
	{
		read >> product;
		if (number == product.getNumber()) {
			product.Show();
			cout << COLOR_CYAN << "Please enter new parts for this item" << endl;
			New.setAll();
			write << New << endl;
			flag = 0;
			break;
		}
		else {
			write << product << endl;
			continue;
		}
	}
	read.close();
	write.close();

	if (flag == 1) cout << COLOR_RED << "This number does not found in list!" << COLOR_RESET << endl;
	else {
		read1.open("Temp.txt", ios::app);
		write1.open("Product.dat");

		while (!read1.eof()) {
			temp = product;
			read1 >> product;
			if (temp.getNumber() == product.getNumber()) {
				write << product;
				break;
			}
			else {
				write1 << product;
				continue;
			}
		}
		cout << COLOR_GREEN << "This product edited." << COLOR_RESET;
	}
}

void Delete(int number) {
	ifstream read, read1;
	ofstream write, write1;
	Product product, old, temp;
	bool flag = 1;

	string nameOfFile = "Product.dat";
	read.open("Product.dat", ios::in);
	write.open("Temp.txt");

	while (!read.eof())
	{
		read >> product;
		if (number == product.getNumber()) {
			product.Show();
			flag = 0;
		}
		else {
			write << product;
			continue;
		}
	}
	read.close();
	write.close();

	if (flag == 1) cout << COLOR_RED << "This number does not found in list!" << COLOR_RESET << endl;
	else {
		read1.open("Temp.txt", ios::app);
		write1.open("Product.dat");

		while (!read1.eof()) {
			temp = product;
			read1 >> product;
			if (temp.getNumber() == product.getNumber()) {
				write << product;
				break;
			}
			else {
				write1 << product;
				continue;
			}
		}
		read1.close();
		write1.close();
		cout << COLOR_GREEN << "This product deleted." << COLOR_RESET;
	}
}

void numberRepeatCheck(int number) {
	Product product;
	string nameOfFile = "Product.dat";
	ifstream File("Product.dat", ios::in);
	bool flag = 1;
	while (!File.eof())
	{
		Product product;
		File >> product;
		if (number == product.getNumber()) {
			product.Show();
			flag = 0;
			break;
		}
		else continue;
	}
	if (flag == 0) throw "repetitive";
	File.close();

}
