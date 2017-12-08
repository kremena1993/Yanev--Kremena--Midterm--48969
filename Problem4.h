#ifndef PROBLEM4_H
#define	PROBLEM4_H

#include <iostream>
using namespace std;

int P4()
{
	int first, second, third, fourth, digit, temp;
	int encryptedNumber;

	cout << "Enter a four digit number to be encrypted: ";
	cin >> digit;
	 if (digit / 1000 > 7 || (digit % 1000)/ 100 > 7 || (digit % 100)/10 > 7 || fourth % 10 > 7 || digit > 9999 || digit < 0) {
	 	cout << "Error! All digits should be between 0-7. Numbers should be positive and with 4 digits! \n";
	 	return 0;
	 }

	first = (digit / 1000 + 5) % 8;
	second = ((digit % 1000) / 100 + 5) % 8;
	third = ((digit % 100) / 10 + 5) % 8;
	fourth = ((digit % 10) + 5) % 8;


	temp = first;
	first = second * 1000;
	second = temp * 100;

	temp = third;
	third = fourth * 10;
	fourth = temp * 1;

	encryptedNumber = first + second + third + fourth;
	cout << "Encrypted number is " << encryptedNumber << endl;

	 int decrypted, num;
	
	 cout << "Enter a four digit encrypted number: ";
	 cin >> num;
	
	 first = num / 1000;
	 second = (num % 1000) / 100;
	 third = (num % 100) / 10;
	 fourth = (num % 10);
	 
	 if (first > 7 || second > 7 || third > 7 || fourth > 7 || digit > 9999 || digit < 0) {
	 	cout << "Error! All digits should be between 0-7. Numbers should be positive and with 4 digits!\n";
	 	return 0;
	 }

	 temp = (first + 3) % 8;
	 first = (second + 3) % 8;
	 second = temp;

	 temp = (third + 3) % 8;
	 third = (fourth + 3) % 8;
	 fourth = temp;
	
	 decrypted = first * 1000 + second * 100 + third * 10 + fourth;
	 cout << "Decrypted number is " << decrypted << endl;
	
 


	return 0;
}
#endif 