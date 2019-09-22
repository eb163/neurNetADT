#pragma once
#include "Layer.h"
#include "OutputNeuron.h"

class OutputLayer : public Layer
{
protected:
	//inherited
	//int numberOfNeurons = 0;
	//Layer* prevLayerPtr = nullptr;
	std::vector<OutputNeuron> neurons;

public:
	void addNeuron();
	void addNeuron(double bias);

	OutputNeuron& getNeuron(int index);

	void connect(Layer& layer);

	void update();
};