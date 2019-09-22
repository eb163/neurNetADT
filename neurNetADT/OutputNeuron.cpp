#include "OutputNeuron.h"

double OutputNeuron::getBias()
{
	return bias;
}

void OutputNeuron::setBias(double new_bias)
{
	bias = new_bias;
}

void OutputNeuron::adjustBias(double delta)
{
	bias += delta;
}

double OutputNeuron::get() const
{
	if (value > bias)
		return value;
	else
		return 0;
}

void OutputNeuron::update()
{
	if (inLayer.empty() == false)
	{
		int size = inLayer.size();
		double currentInput = 0, currentWeight = 0;
		double sum = 0;
		for (int i = 0; i < size; ++i)
		{
			//get the total sum from all connected input neurons
			currentInput = inLayer.at(i).getNeuron()->get();
			currentWeight = inLayer.at(i).getWeight();
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

bool OutputNeuron::connectIn(Neuron& inLine)
{
	inLayer.push_back(Connection(inLine, 1));
	return true;
}

bool OutputNeuron::connectIn(Neuron& inLine, double weight)
{
	inLayer.push_back(Connection(inLine, weight));
	return true;
}