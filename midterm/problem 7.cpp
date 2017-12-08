#include <iostream>
using namespace std;

#include "primes.h"

int main(int argc, char** argv) {
    unsigned short number=0, powCtr=0, numPrm=0;
    Primes values;
   

    cout<<"Enter a number between 2 and 10000"<<endl;
    cin>>number; //input number to find the prime factors
    while (cin.fail() || number<2 || number>10000) { //validate input range
        cout<<"ERROR! Invalid Entry! Try Again!"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>number;
    }
    values.prime=new Prime[number/2]; //set array to half the size of input number

    for (int i=2;i<=number;i++) { //loop through to find factors
        while (number%i==0) {
            number/=i;
            powCtr++;
        }
        values.prime[numPrm].power=powCtr;
        values.prime[numPrm].prime=i;
        if (powCtr>0) numPrm++;
        powCtr=0;
    }

    for (int i=0;i<numPrm;i++) {
        cout<<"Prime: "<<values.prime[i].prime<<"   Power: "<<values.prime[i].power<<endl;
    }

    delete [] values.prime;

    return 0;
}
