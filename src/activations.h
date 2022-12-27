#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H

typedef double (*ActivationFunction)(double);

double relu(double sum);
double drelu(double sum);

#endif // ACTIVATIONS_H
