#pragma once
#include <vector>
#include "Neuron.h"

class Layer
{
protected:
	int numberOfNeurons = 0;
	Layer* prevLayerPtr = nullptr;

	//removing Neurons from a Layer will require a Layer to have a reference to the next Layer to
	//clean all references of the removed Neuron from the next Layer's neurons
	//Layer* nextLayerPtr = nullptr;

public:
	int getNeuronCount();

	Layer* getPrevLayerPtr();
	void setPrevLayerPtr(Layer& prev);

	virtual Neuron& getNeuron(int index) = 0;

	/*
	Layer* getNextLayerPtr();
	void setNextLayerPtr(Layer& next);
	*/

	virtual void addNeuron() = 0;
	//TODO: define behavior when adding Neurons in the descendant layer classes

	//virtual void removeNeuron() = 0;
	//TODO: define behavior when removing Neurons in the descendant layer classes

	virtual void update() = 0;

};