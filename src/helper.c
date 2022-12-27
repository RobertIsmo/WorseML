#include <stdlib.h>
#include <time.h>
#include "helper.h"

NumberList createNumberList(int size) {
	int *element = calloc(size, sizeof(int));
	NumberList v = {size, element};
	return v;
}

void seed() {
	srand(time(NULL)*time(NULL));
}
double randomDec() {
   	return (double)rand() / RAND_MAX;
}
double randomInt(double lower, double upper) {
	int diff = upper - lower;
	double amount = (double)diff*randomDec();
	return lower + amount;
}