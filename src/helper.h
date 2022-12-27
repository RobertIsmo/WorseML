#ifndef HELPER_H
#define HELPER_H

typedef struct {
	int size;
	int *element;
} NumberList;
NumberList createNumberList(int size);

void seed();
double randomDec();
double randomInt(double lower, double upper);


#endif // HELPER_H