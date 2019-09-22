#include "HiddenLayer.h"
#include <iostream>

using std::cout;
using std::endl;

void HiddenLayer::addNeuron()
{
	//create neuron
	HiddenNeuron n;
	n.setBias(0);

	//connect all neurons in the prev layer to this neuron
	int prevNeuronCount = prevLayerPtr->getNeuronCount();
	for (int i = 0; i < prevNeuronCount; ++i)
	{
		n.connectIn(prevLayerPtr->getNeuron(i), 1);
	}

	//add this neuron to the vector
	neurons.push_back(n);
	++numberOfNeurons;
}

void HiddenLayer::addNeuron(double bias)
{
	//create neuron
	HiddenNeuron n;
	n.setBias(bias);

	//cout << "DEBUG: HiddenLayer(" << this << ") previous Layer(" << prevLayerPtr << ") neuron count = " << prevLayerPtr->getNeuronCount() << endl;
	//connect all neurons in the prev layer to this neuron
	int prevNeuronCount = prevLayerPtr->getNeuronCount();
	for (int i = 0; i < prevNeuronCount; ++i)
	{
		n.connectIn(prevLayerPtr->getNeuron(i), 1);
	}

	//add this neuron to the vector
	neurons.push_back(n);
	++numberOfNeurons;
}

HiddenNeuron& HiddenLayer::getNeuron(int index)
{
	return neurons.at(index);
}

void HiddenLayer::connect(Layer& layer)
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

void HiddenLayer::update()
{
	//cout << "DEBUG: HiddenLayer(" << this << ") Neuron count: " << numberOfNeurons << endl;
	if(numberOfNeurons > 0)
	{ 
		for (int i = 0; i < numberOfNeurons; ++i)
		{
			neurons.at(i).update();
		}
	}
}