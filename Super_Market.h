#pragma once
#include <string>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

class Product {
private:
	int number;
	string name;
	float price;
	int count;
	//Date date;
public:
	//Number 
	void setNumber(int number);
	int getNumber();
	//Name 
	void setName(string name);
	string getName();
	//Price 
	void setPrice(float price);
	float getPrice();
	//Count 
	void setCount(int count);
	int getCount();
	//Show Obj Items
	void Show();
	//All Setter 
	void setAll();

	void Add() {
		cout << "";
	}
	//Operator <<(ostream) Overloaded For Product Obj
	friend ostream& operator << (ostream& out, const Product& attribute);
	//Operator <<(ofstream) Overloaded For Product Obj
	friend ofstream& operator << (ofstream& out, Product& attribute);
	//Operator <<(ifstream) Overloaded For Product Obj
	friend ifstream& operator >> (ifstream& in, Product& attribute);
	//Operator <<(fstream) Overloaded For Product Obj
	friend fstream& operator >> (fstream& in, Product& attribute);
};

class Date {
private:
	int day;
	int month;
	int year;
public:
	//Date 
	void setDay(int day);
	int getDay();
	//Month 
	void setMonth(int month);
	int getMonth();
	//Year
	void setYear(int year);
	int getYear();

	//Operator <<(ostream) Overloaded For Date Obj
	friend ostream& operator << (ostream& out, const Date& attribute);
	//Operator >>(ifstream) Overloaded For Date Obj
	//friend ifstream& operator >> (ifstream& in, Date& attribute);
};

void inputValidation(istream& cin);
void writeInList(Product product);
void readFromList();
void Find(int number);
int countFileLine();
void Edit(int number);
void Delete(int number);
void numberRepeatCheck(int number);


