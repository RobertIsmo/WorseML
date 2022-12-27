#ifndef WRITER_H
#define WRITER_H

#include "algebra.h"
#include "perceptron.h"
#include "network.h"

void tab(int times);

void print_vector(const char *name, Vector x);
void print_perceptron(const char *name, Perceptron x);
void print_network(const char *name, Network nn);

#endif // WRITER_H