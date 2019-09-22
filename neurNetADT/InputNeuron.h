#pragma once
#include "Neuron.h"

class InputNeuron : public Neuron
{
private:
	double input = 0; //value that theInputNeuron passes to all connected next layer HiddenNeurons
	//the current plan is for each layer to contian references to the previous layer
	//so the input layer has no references to any next layer

public:
	InputNeuron(double value);

	double get() const; // returns input value
	void read(double value); // updates input value


};