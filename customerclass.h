#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

class Customer {
public:
	Customer(string n, int m, string a, double b) {
		name = n;
		mobile = m;
		address = a;
		balance = b;
	}
	void CustSet(string n, int m, string a, double b) {
		name = n;
		mobile = m;
		address = a;
		balance = b;
	}
	void display() {
		cout << "Name: " << name << endl;
		cout << "Mobile: " << mobile << endl;
		cout << "Address: " << address << endl;
		cout << "Balance: " << balance << endl;
	}

	string getName() const {
		return name;
	}

	int getMobile() const {
		return mobile;
	}

	string getAddress() const {
		return address;
	}

	double getBalance() const {
		return balance;
	}

	void setBalance(double balance) {
		this->balance = balance;
	}
	void setName(string n) {
		this->name = n;
	}
	void setMobile(int m) {
		this->mobile = m;
	}
	void setAddress(string a) {
		this->address = a;
	}

	bool operator <(const Customer& c)
	{
		if (mobile < c.mobile)
			return true;
		else
			return false;
	}
	bool operator ==(const Customer& c) 
	{
		cout << "= = " << endl;
		if (mobile == c.mobile)
			return true;
		else
			return false;
	}
	bool operator >(const Customer& c) 
	{
		if (mobile > c.mobile)
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream& out, const Customer& C) 
	{
		out << left << setw(15) << C.name;
		out << left << setw(14) << C.mobile;
		out << left << setw(20) << C.address;
		out << left << setw(10) << C.balance;
		out << endl;
		return out;
	}
private:
	string name;
	int mobile;
	string address;
	double balance;
};