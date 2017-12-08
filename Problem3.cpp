#include <iostream>
#include <stdlib.h>
#include <map>
#include "statsResult.h"

using namespace std;

 float mean(int array[], int size);
 float median(int array[], int size);
 int * mode(int array[], int size);


 //Original function of mode is int ! how to return value the proper way ,136 ?
 int P3()
 {
	int size;
	
	cout << "How long is the array? ";
	cin >> size;
	int *array = new int[size];
	cout << "Please enter " << size << " integer numbers: ";

	for (int i = 0; i < size; i ++) {
	 	cin >> array[i];
	}

	statsResult * stats = avgMedMode(array, size);
	printStat(stats);

	delete array;
	return 0;
}
 
 statsResult *avgMedMode(int * array, int size) {
 	statsResult * s = new statsResult;
 	s->avg = mean(array, size);
 	s->median = median(array, size);
	int *modes = mode(array, size);
 	s->mode = modes + 2;
 	s->nModes = modes[0];
 	s->maxFreq = modes[1];

 	return s;
 }

void printStat(statsResult * stats) {

	cout <<"The mean of the array is " << stats->avg << endl;

	cout << "The median of the array is " << stats->median << endl;

	cout << "Number of modes: " << stats->nModes << "\nMax. frequency of mode 1: " << stats->maxFreq << "\nModes: ";
	for (int i = 0; i < stats->nModes; i ++) {
		cout << stats->mode[i] << " ";
	}
	cout << "\n";

}

 float mean(int array[], int size )
 { 
	 float average = 0;
	 for (int i = 0; i<size; i++)
		 average += array[i];
	 return ((float)average) / size;
 }
 
int compare_function(const void *a,const void *b) {
	int *x = (int *) a;
	int *y = (int *) b;
	return *x - *y;
}

float median(int array[], int size) {
 	qsort (array, size, sizeof(int), compare_function);
	if (size % 2) {
		return (float)array[size / 2];
	} else {
		return ((float)(array[size / 2 - 1] + array[size / 2])) / 2.0;
	}
}


// use a map to count the frequency of each element in the array
std::map<int,int> modes;

// compare keys in the map based on their values
int comp_modes(const void *a,const void *b) {
	int *x = (int *) a;
	int *y = (int *) b;
	return modes[*y] - modes[*x];
}

int * mode(int array[], int size) {

	modes.clear();

	int i;
	for (i = 0; i < size; i++) {
		if (modes.find(array[i]) == modes.end()) {
			modes[array[i]] = 0;
		}
		modes[array[i]] += 1;
	}
	// get the number of modes
	int n_modes = modes.size();
	
	// allocate memory for the results array
 	int * result = new int[n_modes + 2];
 	result[0] = n_modes;

 	// copy the unsorted modes to the results array
 	i = 0;
	for (std::map<int,int>::iterator it=modes.begin(); it != modes.end(); ++it) {
		result[2 + i] = it->first;
		i ++;
	}

	// sort the modes based on their frequencies in descending order
	qsort(result + 2, n_modes, sizeof(int), comp_modes);

	// get the maximum frequency
	result[1] = modes[result[2]];

 	return result;
}