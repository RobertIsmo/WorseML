#include <stdio.h>
#include "writer.h"
#include "network.h"

void tab(int times) {
	for(int i = 0; i < times; i++) {
		printf("    ");
	}
}

void print_vector(const char *name, Vector x) {
	printf("Vector %s: [", name);
	for (int i = 0; i < x.size; i++) {
		printf("%s%.4f", i > 0 ? ", " : "", x.element[i]);
	}
	printf("]\n");
}
void print_numberlist(const char *name, NumberList x) {
	printf("NumberList %s: [", name);
	for (int i = 0; i < x.size; i++) {
		printf("%s%d", i > 0 ? ", " : "", x.element[i]);
	}
	printf("]\n");
}
void print_perceptron(const char *name, Perceptron x) {
	printf("Perceptron %s: input_size=%d, bias=%.2f, weights=[",
	       name, x.input_size, x.bias);
	for (int i = 0; i < x.input_size; i++) {
		printf("%s%.4f", i > 0 ? ", " : "", x.weights[i]);
	}
	printf("]\n");
}
void print_network(const char *name, Network nn) {
	printf("Network %s:\n", name);
	tab(1);
	printf("input_size: %d\n", nn.input_size);
	tab(1);
	printf("layers:\n");
	tab(2);
	print_numberlist("", nn.layers);
	tab(1);
	printf("nodes:\n");
	for (int i = 0; i < nn.layers.size; i++) {
		char layer[32];
		snprintf(layer, sizeof layer, "layer %d", i+1);
		tab(2);
		printf("%s\n", layer);
		for(int j = 0; j < nn.layers.element[i]; j++) {
			char number[32];
			snprintf(number, sizeof number, "node %d", j+1);
			tab(3);
			print_perceptron(number, nn.nodes[i][j]);
		}
	}
}