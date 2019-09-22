#pragma once
#include <stdexcept>

class Neuron;

//connections are used by a Neuron to refer to the connected Neurons
//from a previous layer

//this means inputNeurons have no connections

//each connection points to a single Neuron

//each connection instance has a weight value used by the
//Neuron owning it to calculate the output value

class Connection
{
private:
	//Neuron* in;
	Neuron* out;
	double weight;

public:

	Connection();
	Connection(Neuron& outLine);
	Connection(Neuron& outLine, double w);

	void setNeuron(Neuron& outLine);
	Neuron* getNeuron();

	void setWeight(double new_weight);
	double getWeight() const;
	void adjustWeight(double delta);
};
