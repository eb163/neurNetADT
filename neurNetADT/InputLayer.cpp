#include "InputLayer.h"

void InputLayer::addNeuron()
{
	InputNeuron n(0);
	neurons.push_back(n);
	++numberOfNeurons;
}

void InputLayer::addNeuron(double input)
{
	InputNeuron n(input);
	neurons.push_back(n);
	++numberOfNeurons;
}

InputNeuron& InputLayer::getNeuron(int index)
{
	return neurons.at(index);
}

void InputLayer::update()
{
	
}