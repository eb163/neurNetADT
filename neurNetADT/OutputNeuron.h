#pragma once
#include "Neuron.h"
#include "Connection.h"
#include <vector>

class OutputNeuron : public Neuron
{
private:
	double value;
	double bias;
	std::vector<Connection> inLayer;

public:

	double getBias();
	void setBias(double new_bias);
	void adjustBias(double delta);

	double get() const;
	void update();

	bool connectIn(Neuron& inLine);
	bool connectIn(Neuron& inLine, double weight);

};