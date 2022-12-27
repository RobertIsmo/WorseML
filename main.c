#include <stdio.h>
#include "helper.h"
#include "writer.h"
#include "network.h"

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "activations.h"
#include "perceptron.h"
#include "algebra.h"

Network InitializeNetwork(
	int input, NumberList layers, ActivationFunction sigma, ActivationFunction dsigma
) {

	Network nn = { input, layers };
	nn.sigma = calloc(layers.size, sizeof(ActivationFunction));
	nn.dsigma = calloc(layers.size, sizeof(ActivationFunction));
	nn.nodes = calloc(layers.size, sizeof(Perceptron *));

	int last_layer = input;
	for(int i = 0; i < layers.size; i++) {
		int size = nn.layers.element[i];

		nn.sigma[i] = sigma;
		nn.dsigma[i] = dsigma;

		nn.nodes[i] = calloc(size, sizeof(Perceptron));
		for(int j = 0; j < size; j++) {
			Perceptron p = InitializePerceptron(last_layer, *nn.sigma, *nn.dsigma);
			nn.nodes[i][j] = p;
			//print_perceptron("", nn.nodes[i][j]);
		}

		last_layer = size;
	}

	return nn;
}
Vector FeedNetwork(Network nn, Vector input) {
	assert(nn.input_size == input.size);
	
	Vector current = input;

	int size = nn.layers.element[0];
	for(int i = 0; i < nn.layers.size; i++) {
		Perceptron *p = nn.nodes[i];
		double next[size];
		for(int j = 0; j < size; j++) {
			next[j] = FeedPerceptron(p[j], current);
		}
		Vector layerOut = createVector(size);
		layerOut.element = &next[0];
		current = layerOut;

		size = nn.layers.element[i+1];
	}

	return current;
}

int main() {
	seed();

	NumberList dimensions = {4, (int[]){4, 3, 4, 5}};
	Network nn = InitializeNetwork(5, dimensions, relu, drelu);
	print_network("before", nn);

	Vector input = { 5, (double[]){1, 0, 0, 0, 0}};
	printf("The network recieved the input:\n");
	print_vector("input", input);
	Vector output = FeedNetwork(nn, input);
	printf("And produced the output:\n");
	print_vector("output:", output);

	print_network("after", nn);
	return 0;
}