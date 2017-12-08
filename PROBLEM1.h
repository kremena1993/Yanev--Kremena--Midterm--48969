#ifndef PROBLEM1_H
#define	PROBLEM1_H

struct Customer
{
	int AccNum,
		Bal,
		Check,
	    Dep;
};
bool P1_AccNumCheck(char AccNum[], int size);
bool P1_digitTest(char AccNum[]);
void P1_Deposits(Customer &customer);
void P1_Checks(Customer &customer);
int P1_read_integer();
int P1();
int P2();
int P3();
int P5();
int P6();
int P5();
#endif 
