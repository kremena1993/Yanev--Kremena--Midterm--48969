#include <iostream>
#include <string>
using namespace std;

#include "PROBLEM1.h"


int P1()
{
	Customer customer;
	int num;
	const int size = 16;
	char AccNum[size];
	cout << "Enter a customer the 5 digit customer account number:> ";
	cin.getline(AccNum, size);
	while (!P1_AccNumCheck(AccNum, size))
	{
		cout << "Enter a customer the 5 digit customer account number:> ";
		cin.getline(AccNum, size);
	}
	cout << "Account Number:> " << AccNum << endl;
	customer.AccNum = atoi(AccNum);
	cout << "What is your balance? :> ";
	customer.Bal = P1_read_integer();

	P1_Checks(customer);
	P1_Deposits(customer);
	
	customer.Bal += customer.Dep - customer.Check;
	if (customer.Bal < 0){

		cout << "You will pay $15 fee for overdrawing your account" << endl;
		customer.Bal -= 15;
	}
	
	cout << "New Balance is:> " << customer.Bal << endl;
	

	return 0;
}
bool P1_AccNumCheck(char AccNum[], int size) // fuction that will check all possibilities
{
	if (!(strlen(AccNum) == 5 && P1_digitTest(AccNum)))
	{
		cout << "Wrong Account number, try again" << endl;
		return false;
	}
	return true;
}
bool P1_digitTest(char AccNum[]) //check digit function
{

	for (int count = 0; count <strlen(AccNum); count++)
	{
		if (!isdigit(AccNum[count]))
			return false;
	}
	return true;
}
void P1_Checks(Customer &customer)
{
	int Check;//how to use it from customer.h
	int total_checks = 0;
	char choice;
	do
	{
		cout << "Enter the amount of a certain check " << endl;
		
		total_checks += P1_read_integer();

		cout << "Would you like to add another checks?(Y/N)" << endl;
		cin >> choice;

	} while ((choice == 'y') || (choice == 'Y'));

	customer.Check = total_checks;
	// calculate gross pay inside loop
	cout << "The total amount of checks is:> " << customer.Check << endl;
	
}
void P1_Deposits(Customer &customer)
{
	
	int Dep;//how to use it from customer.h
	int total_deposits = 0;
	char choice;
	do
	{
		cout << "Enter the amount of deposits " << endl;

		total_deposits += P1_read_integer();
		
		cout << "Would you like to add another deposit?(Y/N)" << endl;
		cin >> choice;

	} while ((choice == 'y') || (choice == 'Y'));
	customer.Dep = total_deposits;
	// calculate gross pay inside loop
	cout << "The total amount of deposits is:> " << customer.Dep << endl;

}

int P1_read_integer(){
	char buf[256] = { 0 };
	bool is_valid;
	do {
		is_valid = true;
		cin.sync();
		cin.getline(buf, 256);
		for (int i = 0; buf[i] != 0; i++) {
			if (!isdigit(buf[i])) {
				is_valid = false;
				cout << "Please, enter an integer: ";
				break;
			}
		}
	} while (!is_valid);
	return atoi(buf);
}