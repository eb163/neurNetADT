#include "NeuralNet.h"

NeuralNet::NeuralNet(std::vector<int> parameters)
{
	//get data for input layer (first parameter in vector)
	numberOfLayers = parameters.size();
	int layerCounter = 0;
	int numberOfNeurons = parameters.at(layerCounter);

	//load the number of neurons into the input layer
	for (int i = 0; i < numberOfNeurons; ++i)
	{
		inLayer.addNeuron();
	}

	++layerCounter;

	//set a pointer for the previous layer iterated
	Layer* prev = &inLayer;

	//update the number of neurons to be loaded
	numberOfNeurons = parameters.at(layerCounter);

	//this is messy
	//outer loop iterates from one hiddenlayer to the next hiddenlayer in the vector
	for (int j = 1; j < numberOfLayers - 1; ++j)
	{
		HiddenLayer hL; //create a temporary hiddenlayer
		hL.connect(*prev); //connect this layer to the prev layer
		for (int i = 0; i < numberOfNeurons; ++i)
		{
			hL.addNeuron(); //add neurons to the current layer
		}
		hiddenLayers.push_back(hL); //store this layer in the vector
		++layerCounter;
		prev = &hiddenLayers.at(hiddenLayers.size() - 1); //update prev pointer
		numberOfNeurons = parameters.at(j + 1); //update number of neurons for the next layer
		//repeat until all hiddenlayers are added
	}

	//load the output layer
	//connect outlayer to prev layer
	outLayer.connect(*prev);

	for (int i = 0; i < numberOfNeurons; ++i)
	{
		outLayer.addNeuron(); //add neurons
	}
	++layerCounter;
	numberOfLayers = layerCounter; //check if this is the right value
}

int NeuralNet::getLayerCount()
{
	return numberOfLayers;
}

void NeuralNet::update()
{
	inLayer.update();
	for (int i = 0; i < hiddenLayers.size(); ++i)
	{
		hiddenLayers.at(i).update();
	}
	outLayer.update();
}

std::vector<double> NeuralNet::getInput()
{
	vector<double> results;
	for (int i = 0; i < inLayer.getNeuronCount(); ++i)
	{
		results.push_back(inLayer.getNeuron(i).get());
	}
	return results;
}

void NeuralNet::setInput(std::vector<double> input)
{
	int i = 0;
	while (i < input.size() && i < inLayer.getNeuronCount())
	{
		double inValue = input.at(i);
		if (inValue != 0)
		{
			inLayer.getNeuron(i).read(inValue);
		}
		++i;
	};
}

std::vector<double> NeuralNet::getOutput()
{
	vector<double> results;
	for (int i = 0; i < outLayer.getNeuronCount(); ++i)
	{
		results.push_back(outLayer.getNeuron(i).get());
	}
	return results;
}