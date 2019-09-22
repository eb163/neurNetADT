#pragma once
#include "Neuron.h"
#include "Layer.h"
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
#include <vector>

class NeuralNet
{
private:
	int numberOfLayers = 0;
	InputLayer inLayer;
	std::vector<HiddenLayer> hiddenLayers;
	OutputLayer outLayer;

public:
	NeuralNet(std::vector<int> parameters);

	int getLayerCount();

	//get layer
	//Layer getLayer();

	void update();

	std::vector<double> getInput();
	void setInput(std::vector<double> input);

	std::vector<double> getOutput();

};