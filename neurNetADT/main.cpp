#include <iostream>
#include "Neuron.h"
#include "HiddenNeuron.h"
#include "InputNeuron.h"
#include "OutputNeuron.h"
#include "Layer.h"
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
#include "NeuralNet.h"

using std::cout;
using std::cin;
using std::endl;

void pause()
{
	char input;
	cout << "\nPress any key to continue...";
	cin >> input;
}

void testConnections()
{
	cout << "Starting connection tests..." << endl;

	HiddenNeuron n1;
	cout << "created Neuron n1..." << endl;

	HiddenNeuron n2;
	cout << "created neuron n2..." << endl;

	cout << "connecting n1 and n2...";
	n2.connectIn(n1);
	cout << "done. \n n1 -> n2" << endl;

	cout << "n1 mem addr: " << &n1 << endl;
	cout << "n2 mem addr: " << &n2 << endl;

	cout << "connection(n2 -> n1) == " << &n2 << " -> " << n2.getInPtr(0) << endl;
	cout << "connection(n2 -> n1) weight : " << n2.getInWeight(0) << endl;

	pause();

	HiddenNeuron n3;
	cout << "created neuron n3..." << endl;

	cout << "connecting n2 and n3...";
	n3.connectIn(n2);
	cout << "done. \n n2 -> n3" << endl;

	cout << "n2 mem addr: " << &n2 << endl;
	cout << "n3 mem addr: " << &n3 << endl;

	cout << "connection(n3 -> n2) == " << &n3 << " -> " << n2.getInPtr(0) << endl;
	cout << "connection(n3 -> n2) weight : " << n2.getInWeight(0) << endl;

	pause();
}

void testCalculations()
{
	cout << "Starting calculations tests..." << endl;
	//create two inputneurons (A and B) with known inputs and weights
	double weightA = 2.0, weightB = 2.5;
	double inputA = 1.0, inputB = 2.0;
	InputNeuron nA(inputA);

	InputNeuron nB(inputB);

	//currently weights are specified during the connection process (somewhat confusing, may want to change this)
	//kind of required with the way connections work
	//each hidden neuron has its own set of connections with weight values that vary from neuron to neuron

	//create a HiddenNeuron C with a specified bias
	double biasC = 0, weightC = 1;
	HiddenNeuron nC;
	nC.setBias(biasC);

	//connect A and B to the inputLayer of C
	nC.connectIn(nA, weightA);
	nC.connectIn(nB, weightB);

	//calculate what the output of C should be using A and B
	//output should be 7 with the given test data
	double goalOutput = (weightA * inputA) + (weightB * inputB) - biasC;
	cout << "Goal output = " << goalOutput << endl; pause();

	//compare the result of the calc method with the goal value
	nC.update();
	cout << "Output of Neuron C = " << nC.get() << endl; pause();

	//add content to test OutputNeuron when OutputNeurons are added
	//create OutputNeuron D
	double biasD = 0;
	OutputNeuron nD;
	nD.setBias(biasD);

	//connect C to D
	nD.connectIn(nC, weightC);
	//test if the output of Neruon C passes the bias of the outputNeuron D
	nD.update();
	cout << "Bias of Neuron D = " << nD.getBias() << endl;
	cout << "Output of Neuron D = " << nD.get() << endl;

	pause();
}

void testInputLayer()
{
	cout << "Starting input layer testing..." << endl;
	double input = 3.99;
	InputLayer iL;
	iL.addNeuron(input);
	cout << "Goal output = " << input << endl;
	cout << "Input Layer neuron output = " << iL.getNeuron(0).get() << endl;
	
	pause();
}

void testHiddenLayer()
{
	cout << "Starting hidden layer testing..." << endl;

	double input1 = 1.9, input2 = 2.0;
	double bias = 1.0;
	double goal = input1 + input2 - bias;

	//create an input layer
	InputLayer inL;
	inL.addNeuron(input1);
	inL.addNeuron(input2);

	//create a hidden layer
	HiddenLayer hL;
	//connect the input layer to the hidden layer
	hL.setPrevLayerPtr(inL);
	//add the neuron (connections are made to the prev layer while adding the neuron)
	hL.addNeuron(bias);

	//calculate
	hL.getNeuron(0).update();

	//test if the resulting calculated output is the expected output
	cout << "Goal = " << goal << endl;
	cout << "HiddenLayer output = " << hL.getNeuron(0).get() << endl;
	pause();

}

void testOutputLayer()
{
	cout << "Starting OutputLayer testing..." << endl;
	double input1 = 1.9, input2 = 3.4;
	double bias = 0.5;
	double goal = input1 + input2 - bias;

	//create an input layer
	InputLayer iL;
	iL.addNeuron(input1);
	iL.addNeuron(input2);

	//create an output layer
	OutputLayer oL;

	//connect the input and output layer
	oL.setPrevLayerPtr(iL);

	//add the neuron to the output layer
	oL.addNeuron(bias);

	//calculate
	oL.getNeuron(0).update();

	//compare results
	cout << "Goal = " << goal << endl;
	cout << "OutputLayer neuron(0) output = " << oL.getNeuron(0).get() << endl;
	pause();
}

void testAllLayers() //try connecting input layer, hidden layer, and output layer
{
	cout << "Starting testing on all layers connected together..." << endl;
	cout << "3 input neurons, 2 hidden neurons, 1 output neuron." << endl;

	//test data
	double input1 = 1.0, input2 = 2.2, input3 = 3.0303; //3 input neurons
	double bias1 = 0.5, bias2 = 0.25, bias3 = 1.05;

	double goal = (((input1 + input2 + input3) - bias1) + ((input1 + input2 + input3) - bias2)) - bias3;

	//create an input layer
	InputLayer inL;
	inL.addNeuron(input1);
	inL.addNeuron(input2);
	inL.addNeuron(input3);

	//create a hidden layer
	HiddenLayer hL;
	hL.connect(inL);
	hL.addNeuron(bias1);
	hL.addNeuron(bias2);

	//create an output layer
	OutputLayer oL;
	oL.connect(hL);
	oL.addNeuron(bias3);

	//calculate
	hL.update();
	oL.update();

	cout << "Goal output = " << goal << endl;
	cout << "Final outLayer output = " << oL.getNeuron(0).get() << endl;
	pause();
}

void testNeuralNet() //try creating a neural net instance and run all the methods associated with it
{
	cout << "Starting neural net tests..." << endl;
	vector<int> nnParameters = {3, 2, 1};
	int goalLayerCount = nnParameters.size();
	cout << "Creating a neural net..." << endl;
	NeuralNet net(nnParameters); //try making a neural net without crashing
	cout << "Goal Layer Number = " << goalLayerCount << endl;
	cout << "Total layers = " << net.getLayerCount() << endl;

	//test passing input of the same size as the in layer
	cout << "\nTest 1: Test inputs of the same size as the input layer." << endl;
	vector<double> testInput1 = { 1.001, 2.2, 3.303 };
	double goalOutput1 = (testInput1.at(0) + testInput1.at(1) + testInput1.at(2)) * 2;
	//biases are currently at 0, weights are currently all 1, basically the hidden layer takes the sum,
	//and the output neuron takes the sum of those two hidden neurons

	cout << "Passing input (" << testInput1.at(0) << ", " << testInput1.at(1) << ", " << testInput1.at(2) << ")" << endl;
	net.setInput(testInput1);
	vector<double> receivedInput1 = net.getInput();
	cout << "Received input (" << receivedInput1.at(0) << ", " << receivedInput1.at(1) << ", " << receivedInput1.at(2) << ")" << endl;

	pause();

	cout << "Goal output = " << goalOutput1 << endl;
	net.update();
	vector<double> output1 = net.getOutput();
	cout << "Neural net output = " << output1.at(0);

	pause();

	//test passing input smaller than the in layer
	cout << "\nTest 2: Test inputs of a smaller size than the input layer." << endl;
	vector<double> testInput2 = { 1.111, 4.222}; //test data would now be 1.111, 4.222, 3.303
	double goalOutput2 = (testInput2.at(0) + testInput2.at(1) + testInput1.at(2)) * 2;

	cout << "Passing input (" << testInput2.at(0) << ", " << testInput2.at(1) << ", " << testInput1.at(2) << ")" << endl;
	net.setInput(testInput2);
	vector<double> receivedInput2 = net.getInput();
	cout << "Received input (" << receivedInput2.at(0) << ", " << receivedInput2.at(1) << ", " << receivedInput2.at(2) << ")" << endl;

	pause();

	cout << "Goal output = " << goalOutput2 << endl;
	net.update();
	vector<double> output2 = net.getOutput();
	cout << "Neural net output = " << output2.at(0);

	pause();

	//test passing input larger than the in layer
	cout << "\nTest 3: Test inputs of a larger size than the input layer." << endl;
	vector<double> testInput3 = { 2.111, 4.222, 6.303, 8.4 };
	double goalOutput3 = (testInput3.at(0) + testInput3.at(1) + testInput3.at(2)) * 2;

	cout << "Passing input (" << testInput3.at(0) << ", " << testInput3.at(1) << ", " << testInput3.at(2) << ", " << testInput3.at(3) << ")" << endl;
	net.setInput(testInput3);
	vector<double> receivedInput3 = net.getInput();
	cout << "Received input (" << receivedInput3.at(0) << ", " << receivedInput3.at(1) << ", " << receivedInput3.at(2) << ")" << endl;

	pause();

	cout << "Goal output = " << goalOutput3 << endl;
	net.update();
	vector<double> output3 = net.getOutput();
	cout << "Neural net output = " << output3.at(0);

	pause();

	//test passing 0s and not changing output
	cout << "\nTest 4: Passing 0s and not changing net output." << endl;
	vector<double> testInput4 = { 0, 0, 0 };
	double goalOutput4 = goalOutput3;

	cout << "Passing input (" << testInput4.at(0) << ", " << testInput4.at(1) << ", " << testInput4.at(2) << ")" << endl;
	net.setInput(testInput4);
	vector<double> receivedInput4 = net.getInput();
	cout << "Received input (" << receivedInput4.at(0) << ", " << receivedInput4.at(1) << ", " << receivedInput4.at(2) << ")" << endl;

	pause();

	cout << "Goal output = " << goalOutput4 << endl;
	net.update();
	vector<double> output4 = net.getOutput();
	cout << "Neural net output = " << output4.at(0);

	pause();

	//test taking output with multiple neurons
}

int main()
{
	cout << "size of an input neuron: " << sizeof(InputNeuron)  << " bytes." << endl;
	cout << "size of a hidden neuron: " << sizeof(HiddenNeuron) << " bytes." << endl;
	cout << "size of a output neuron: " << sizeof(OutputNeuron) << " bytes." << endl;
	cout << "size of a basic connection: " << sizeof(Connection) << " bytes." << endl;
	cout << "size of an empty input layer: " << sizeof(InputLayer) << " bytes." << endl;
	cout << "size of an empty hidden layer: " << sizeof(HiddenLayer) << " bytes." << endl;
	cout << "size of an empty output layer: " << sizeof(OutputLayer) << " bytes." << endl;
	pause();

	//testConnections();

	//testCalculations();

	//testInputLayer();

	//testHiddenLayer();

	//testOutputLayer();

	//testAllLayers();

	testNeuralNet();

	return 0;
}