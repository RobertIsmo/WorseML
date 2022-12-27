#include "activations.h"

double relu(double sum) {
	if(sum < 0) return 0;
	return sum;
}
double drelu(double sum) {
	if(sum < 0) return 0;
	return 1;
}