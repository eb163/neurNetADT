#pragma once
#include "Neuron.h"
#include "Connection.h"
#include <vector>

using std::vector;

class HiddenNeuron : public Neuron
{
private:
	double value;

	double bias;

	//double weight; //may or may not be used here, might need a seperate class for connections instead

	//Neuron* inLayer;
	vector<Connection> inLayer;
	//used for connecting this neuron to previous neurons
	//most likely would need to be an array or vector

	//Neuron* outLayer; 
	//vector<Connection<Neuron>> outLayer;
	//used for connecting this neuron to the next layer of neurons
	//most likely would need to be an array or vector


public:

	double get() const;

	void update();

	double getBias() const;

	void setBias(double new_bias);

	void adjustBias(double delta);

	//Connection<Neuron>& getInConnection(int index); //this isn't working

	Neuron* getInPtr(int index);

	double getInWeight(int index);

	bool connectIn(Neuron& in);

	bool connectIn(Neuron& in, double weight);

	//could add a function for disconnecting neurons
};