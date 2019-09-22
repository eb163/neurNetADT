#include "OutputLayer.h"
#include <iostream>

using std::cout;
using std::endl;

void OutputLayer::addNeuron()
{
	//create an OutputNeuron
	OutputNeuron n;
	n.setBias(0);

	//connect it to the previous layer
	int prevNeuronTotal = prevLayerPtr->getNeuronCount();

	for (int i = 0; i < prevNeuronTotal; ++i)
	{
		n.connectIn(prevLayerPtr->getNeuron(i), 1);
	}

	//add it to this layer
	neurons.push_back(n);
	++numberOfNeurons;
}

void OutputLayer::addNeuron(double bias)
{
	//create an OutputNeuron
	OutputNeuron n;
	n.setBias(bias);

	//connect it to the previous layer
	int prevNeuronTotal = prevLayerPtr->getNeuronCount();

	for (int i = 0; i < prevNeuronTotal; ++i)
	{
		n.connectIn(prevLayerPtr->getNeuron(i), 1);
	}

	//add it to this layer
	neurons.push_back(n);
	++numberOfNeurons;
}

OutputNeuron& OutputLayer::getNeuron(int index)
{
	return neurons.at(index);
}

void OutputLayer::connect(Layer& layer)
{
	prevLayerPtr = &layer;
	/*
	for (int i = 0; i < numberOfNeurons; ++i)
	{
	for (int j = 0; j < prevLayerPtr->getNeuronCount(); ++j)
	{
	neurons.at(i).connectIn(prevLayerPtr->getNeuron(j));
	}
	}
	*/
}

void OutputLayer::update()
{
	//cout << "DEBUG: OutLayer(" << this << ") Neuron count: " << numberOfNeurons << endl;
	if (numberOfNeurons > 0)
	{
		for (int i = 0; i < numberOfNeurons; ++i)
		{
			neurons.at(i).update();
		}
	}
}