#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "perceptron.h"
#include "helper.h"
#include "algebra.h"

#include <stdio.h>

Perceptron InitializePerceptron(int input_size, ActivationFunction f, ActivationFunction d) {
	double weights[input_size];
	double bias;
	bias = -randomDec();
	for(int i = 0; i < input_size; i++) {
		weights[i] = randomDec();
	}
	Perceptron p = { input_size, bias, f, d };
	p.weights = calloc(1, sizeof(weights));
	memcpy(p.weights, weights, sizeof(weights));
	return p;
}
double FeedPerceptron(Perceptron p, Vector input) {
	assert(p.input_size == input.size);
	double sum = 0;
	for(int i = 0; i < p.input_size; i++) {
		sum += p.weights[i] * input.element[i];
	}
	return p.f(sum);
}
double TrainPerceptron_IN_PLACE(Perceptron p, Vector input, double output, double learning_rate) {
	assert(p.input_size == input.size);
	double sum = 0;
	for(int i = 0; i < p.input_size; i++) {
		sum += p.weights[i] * input.element[i];
		p.weights++;
		input.element++;
	}

	double predicted = p.f(sum);
	double error = output - predicted;

	double del = error * p.d(sum) * learning_rate;
	p.bias += del;
	for(int i = 0; i < p.input_size; i++) {
		p.weights[i] += input.element[i] * del;
	}
	return predicted;
}
