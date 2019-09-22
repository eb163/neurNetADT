#pragma once
#include "Layer.h"
#include "HiddenNeuron.h"

class HiddenLayer : public Layer
{
protected:
	//inherited
	//int numberOfNeurons = 0;
	//Layer* prevLayerPtr = nullptr;
	std::vector<HiddenNeuron> neurons;
public:
	void addNeuron();
	void addNeuron(double bias);
	HiddenNeuron& getNeuron(int index);
	void connect(Layer& layer);
	void update();
};