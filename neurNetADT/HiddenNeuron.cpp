#include "HiddenNeuron.h"
#include <iostream>

using std::cout;
using std::endl;

double HiddenNeuron::get() const
{
	if (value > bias)
	{
		return value;
	}
	else
	{
		return 0;
	}
}

void HiddenNeuron::update()
{
	//cout << "DEBUG: HiddenNeuron" << this << " inLayer.size() : " << inLayer.size() << endl;
	if (inLayer.empty() == false)
	{
		int size = inLayer.size();
		double currentInput = 0, currentWeight = 0;
		double sum = 0;
		for (int i = 0; i < size; ++i)
		{
			//get the total sum from all connected input neurons
			currentInput = getInPtr(i)->get();
			currentWeight = getInWeight(i);
			sum += (currentInput * currentWeight);
		}
		//subtract bias from sum
		sum -= bias;
		//result is output
		value = sum;
	}
	else
		value = 0;
}

double HiddenNeuron::getBias() const
{
	return bias;
}

void HiddenNeuron::setBias(double new_bias)
{
	bias = new_bias;
}

void HiddenNeuron::adjustBias(double delta)
{
	bias += delta;
}

/*
Connection<Neuron>& Neuron::getInConnection(int index)
{
return inLayer.at(index);
}
*/

Neuron* HiddenNeuron::getInPtr(int index)
{
	return inLayer.at(index).getNeuron();
}

double HiddenNeuron::getInWeight(int index)
{
	return inLayer.at(index).getWeight();
}


bool HiddenNeuron::connectIn(Neuron& in)
{
	//Neuron* n_ptr = &in;
	inLayer.push_back(Connection(in, 1));
	return true;
}


bool HiddenNeuron::connectIn(Neuron& in, double weight)
{
	//Neuron* n_ptr = &in;
	inLayer.push_back(Connection(in, weight));
	return true;
}