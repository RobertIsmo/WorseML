#ifndef ALGEBRA_H
#define ALGEBRA_H

typedef struct {
	int size;
	double *element;
} Vector;
Vector createVector(int size);

#endif // ALGEBRA_H