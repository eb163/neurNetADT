#pragma once
#include "Layer.h"
#include "InputNeuron.h"

class InputLayer : public Layer
{
private:
	//inherited
	//int numberOfNeurons = 0;
	//std::vector<Neuron> neurons;
	//Layer* prevLayerPtr = nullptr;
	std::vector<InputNeuron> neurons;
public:
	void addNeuron();
	void addNeuron(double input);
	InputNeuron& getNeuron(int index);
	void update();
};