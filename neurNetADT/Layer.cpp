#include "Layer.h"

int Layer::getNeuronCount()
{
	return numberOfNeurons;
}

Layer* Layer::getPrevLayerPtr()
{
	return prevLayerPtr;
	//TODO: throw exception if ptr is null
}

void Layer::setPrevLayerPtr(Layer& prev)
{
	prevLayerPtr = &prev;
}
/*
Neuron& Layer::getNeuron(int index)
{
	return neurons.at(index);
}
*/