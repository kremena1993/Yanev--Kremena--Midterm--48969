#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Employee {
	string Ename;
	int hours;
	int rate;
};
int pay(Employee*);
void getEmpInfo(Employee*);
void formatCheck(Employee*, string);
bool validEmp(Employee *);

int P2()
{
	int numEmp;

	cout << "Enter the amount of employees that you would like to input?\n";
	cin >> numEmp;

	Employee **arr = new Employee *[numEmp];
	for (int i = 0; i != numEmp; i++)
		*(arr + i) = new Employee;

	cout << "Enter the date: ";
	string date;
	cin >> date;
	cout << endl;
	int count = 0;
	// the number of employees entered 
	// get employee info
	// and print check while employee info is valid
	while (count != numEmp) {
		getEmpInfo(*(arr + count));
		
		if (validEmp(*(arr + count)))
			formatCheck(*(arr + count), date);
		else {
			cout << "\nInvalid info.\n";
			return 0;
		}
		count++;
	}

	for (int i = 0; i != numEmp; i++) {
		delete *(arr + i);
	}
	delete[]arr;

	return 0;
}
void getEmpInfo(Employee *e) {
	cout << "Enter the employee name: ";
	cin.ignore();
	getline(cin, e->Ename);
	cout << "Enter the pay rate: ";
	cin >> e->rate;
	cout << "Enter the hours worked: ";
	cin >> e->hours;
}
bool validEmp(Employee *e) {
	if (e->rate < 0 || e->hours < 0)
		return false;
	return true;
}
int pay(Employee* e) {
	// total pay
	int rate0 = 0;  
	// r1 holds pay rate
	int rate1 = e->rate;   
	// r2 holds hours worked
	int rate2 = e->hours;    
	int rate3;      
	//hours->pay differential
	int rate4;               

	// check if triple time applies
	if (rate2 > 40) {
		// hours > 40 worked
		rate4 = rate2 - 40;  
		// triple time pay
		rate3 = rate1 * 3;            
		rate3 = rate3 * rate4; 
		// move hours into double time
		rate2 = rate2 - rate4;           
		rate0 = rate0 + rate3;           
	}

	// check if double time applies
	if (rate2 > 20) {
		rate4 = rate2 - 20;          
		rate3 = rate1 * 2;          
		rate3 = rate3 * rate4;          
		rate2 = rate2 - rate4;           
		rate0 = rate0 + rate3;          
	}

	// check if regula
	if (rate1 > 0) {
		rate3 = rate1 * rate2;
		rate0 = rate0 + rate3;
	}
	return rate0;
}


// Function prints a "check" for employee
void formatCheck(Employee *e, string date) {
	cout << setw(40) << right << date << endl << endl
		<< left << "Pay to the order of: " << e->Ename
		<< setw(20 - (e->Ename).size()) << right << "$ " << pay(e) << endl;

	cout << endl;
}