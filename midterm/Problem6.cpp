#include <iostream>
#include <iomanip>
using namespace std;

int P6()
{
	cout << "a)\n";
	// 2.125 -> hex, binary, octal
	cout << "base: " << setw(6) << "10" <<
		setw(6) << "16" << setw(8) << "2" << setw(6) << "8" << endl;
	cout << setw(12) << "2.125" <<
		setw(6) << "2.2" << setw(8) << "10.001" << setw(6) << "2.1"
		<< endl;
	// -2.125 -> hex, binary, octal
	cout << setw(12) << "-2.125" <<
		setw(6) << "5.C" << setw(8) << "101.11" << setw(6) << "5.6"
		<< endl;

	cout << "b)\n";
	cout << "46666601 = 1.09999991" << endl;
	cout << "46666602 = 2.19999981" << endl;
	cout << "B9999AFE = -0.58750045" << endl;
	return 0;
}