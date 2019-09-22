#include "Connection.h"

Connection::Connection()
{
	//in = nullptr;
	out = nullptr;
	weight = 0;
}

Connection::Connection(Neuron& outLine)
{
	//in = nullptr;
	out = &outLine;
	weight = 0;
}

Connection::Connection(Neuron& outLine, double w)
{
	out = &outLine;
	weight = w;
}

void Connection::setNeuron(Neuron& outLine)
{
	out = &outLine;
}


Neuron* Connection::getNeuron()
{
	if (out == nullptr)
		throw std::range_error("Error: No connected neuron.");
	else return out;
	//throw exception if out is nullptr
}

void Connection::setWeight(double new_weight)
{
	weight = new_weight;
}

double Connection::getWeight() const
{
	return weight;
}

void Connection::adjustWeight(double delta)
{
	weight += delta;
}