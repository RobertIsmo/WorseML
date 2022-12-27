#ifndef NETWORK_H
#define NETWORK_H

#include "helper.h"

typedef struct {
	int input_size;
	NumberList layers;

	ActivationFunction *sigma;
	ActivationFunction *dsigma;
	Perceptron **nodes;
} Network;

#endif // NETWORK_H