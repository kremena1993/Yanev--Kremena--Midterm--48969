#ifndef STATSRESULT
#define STATSRESULT

struct statsResult
{
	float avg;
	float median;
	int * mode;   //array containing the modes
	int nModes;  //number of modes in the array
	int maxFreq; //max frequency of modes
};
#endif

statsResult *avgMedMode(int * array, int size);
void printStat(statsResult * stats);
