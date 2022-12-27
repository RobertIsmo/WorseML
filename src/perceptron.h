#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "activations.h"
#include "algebra.h"

typedef struct {
	int input_size;
	double bias;
	ActivationFunction f;
	ActivationFunction d;
	double *weights;
} Perceptron;

Perceptron InitializePerceptron(int input_size, ActivationFunction f, ActivationFunction d);
double FeedPerceptron(Perceptron p, Vector input);
double TrainPerceptron_IN_PLACE(Perceptron p, Vector input, double output, double learning_rate);

#endif // TYPES_H
