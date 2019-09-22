#include "InputNeuron.h"

InputNeuron::InputNeuron(double value)
{
	input = value;
}

double InputNeuron::get() const
{
	return input;
}

void InputNeuron::read(double value)
{
	input = value;
}