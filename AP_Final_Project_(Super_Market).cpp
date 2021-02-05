#include "Super_Market.h"

using namespace std;

int main()
{
	while (true) {
		cout << COLOR_YELLOW << "\t\t\t\t\t\t" << "Super Market Billing" << endl;
		cout << "\t\t\t\t\t\t" << "====================" << COLOR_RESET << endl;
		//Print Main Menu
		cout << COLOR_BLUE << endl << "1." << "Bill Report" << endl
			<< "2." << "Add/Remove/Edit Item" << endl
			<< "3." << "Show Item Details" << endl
			<< "4." << "Exit" << endl;
		//Get Input
		cout << "Please Enter Required Option :";
		int Key;
		cin >> Key;
		system("cls");
		//Cin Validation
		if (cin.fail()) {
			inputValidation(cin);
			continue;
		}
		//First Switch Case Main Menu
		switch (Key) {
		case 1: {
			/*
			//Ask for ID
			cout << COLOR_CYAN << "Please enter ID :";
			//Get Input
			int ID;
			cin >> ID;*/
			try {
				readFromList();
			}
			catch (int number) {
				cerr << COLOR_RED << "Some thing went wrong please try again !";
				std::this_thread::sleep_for(std::chrono::milliseconds(3050));
				system("cls");
				break;
			}
			cout << COLOR_CYAN << "To go back to main menu --> ";
			system("pause");
			system("cls");
			break;

		}
		case 2: {
			bool flag = 1;
			do {
				//Print Second Menu
				cout << COLOR_CYAN << endl << "Bill Editor" << endl;
				cout << "===========" << COLOR_RESET << endl;
				cout << COLOR_CYAN << "1." << "Add Item Details" << endl
					<< "2." << "Edit Item Details" << endl
					<< "3." << "Delete Item Detail" << endl
					<< "4." << "Back to Main Menu" << endl;
				//Get Input
				cout << "Please Enter Required Option :";
				int secondKey;
				cin >> secondKey;
				system("cls");
				//Cin Validation
				if (cin.fail()) {
					inputValidation(cin);
					continue;
				}
				//Second Switch Case 
				switch (secondKey) {
				case 1: {
					Product product;
					product.setAll();
					writeInList(product);
					cout << COLOR_GREEN << "The product added." << COLOR_RESET << endl;
					cout << COLOR_CYAN << product;
					std::this_thread::sleep_for(std::chrono::milliseconds(3050));
					system("cls");
					continue;
				}
				case 2: {
					//Ask For Number To Edit
					do {
						cout << COLOR_CYAN << "Please enter number :";
						int number;
						cin >> number;
						if (cin.fail() || number <= 0) inputValidation(cin);
						else {
							try {
								Edit(number);
							}
							//Exeption Handling
							catch (int number) {
								cerr << COLOR_RED << "Some thing went wrong please try again !";
								std::this_thread::sleep_for(std::chrono::milliseconds(3050));
								system("cls");
								break;
							}
							break;
						}
					} while (true);
					break;
				}
				case 3: {
					//Ask For Number To Delete
					do {
						cout << COLOR_CYAN << "Please enter number :";
						int number;
						cin >> number;
						if (cin.fail() || number <= 0) inputValidation(cin);
						else {
							try {
								Delete(number);
							}
							//Exeption Handling
							catch (int number) {
								cerr << COLOR_RED << "Some thing went wrong please try again !";
								std::this_thread::sleep_for(std::chrono::milliseconds(3050));
								system("cls");
								break;
							}
							break;
						}
					} while (true);
					break;
				}
				case 4: {
					flag = 0;
					break;
				}
				default: {
					cout << COLOR_RED << "The entered number was wrong please try again!" << COLOR_RESET << endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(1050));
					system("cls");
				}
				}
			} while (flag);
			break;
		}
		case 3: {
			cout << "File Line Number is:" << countFileLine() << endl;
			cout << COLOR_CYAN << "Please enter item number:";
			int number;
			cin >> number;
			//Cin Validation
			if (cin.fail()) {
				inputValidation(cin);
				continue;
			}
			try {
				Find(number);
			}
			//Exeption Handling
			catch (const char*) {
				cerr << COLOR_RED << "Your input is wrong please try again !" << COLOR_RESET << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(3050));
				system("cls");
				break;
			}
			catch (int n) {
				cerr << COLOR_RED << "Input number is not found in list please try again !" << COLOR_RESET << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(3050));
				system("cls");
				break;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(3050));
			system("cls");
			break;
		}
		case 4: {
			while (true) {
				//Make Sure User Want To Exit Or No 
				cout << COLOR_CYAN << "Do you really want to exit ?" << endl;
				cout << "If yes enter 0 and if you want to continue enter 1:";
				bool Key;
				cin >> Key;
				cout << COLOR_RESET;
				//Cin Validation
				if (cin.fail()) {
					inputValidation(cin);
					continue;
				}
				system("cls");
				if (Key == 0) {
					cout << COLOR_YELLOW << endl << endl << "Thank you and Bye :)" << COLOR_RESET << endl;
					return 0;
				}
				else break;
			}
			break;
		}
		default: {
			cout << COLOR_RED << "The entered number was wrong please try again!" << COLOR_RESET << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1050));
			system("cls");
		}
		}
	}
}


