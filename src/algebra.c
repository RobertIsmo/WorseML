#include <stdlib.h>
#include "algebra.h"

Vector createVector(int size) {
	double *element = calloc(size, sizeof(double));
	Vector v = {size, element};
	return v;
}