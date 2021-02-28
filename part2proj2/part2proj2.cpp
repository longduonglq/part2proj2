// part2proj2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <limits>
#include "RandomGenerator.h"
#include "IncrementalDistribution.h"
#include "GaussianRandom.h"
#include "ui/MixedColumn.h"
#include "ui/Table.h"
#include "ui/config.h"

using namespace std;

void diplayParameters(long seed, long multiplier, long increment, long modulus)
{
	cout << "Parameters: Seed = " << seed 
		<< ", Multiplier = " << multiplier 
		<< ", Increment = " << increment 
		<< ", Modulus = " << modulus << endl;
}

void displayDistribution(const long frequency[10])
{
	auto intervalColumn = make_unique<MixedColumn>(config::DEFAULT_LEFT_PADDING, config::DEFAULT_RIGHT_PADDING, L"Range");
	auto frequencyColumn = make_unique<MixedColumn>(config::DEFAULT_LEFT_PADDING, config::DEFAULT_RIGHT_PADDING, L"Frequency");
	auto graphColumn = make_unique<MixedColumn>(config::DEFAULT_LEFT_PADDING, config::DEFAULT_RIGHT_PADDING, L"Graph");

	const float increment = 0.1;
	const long maxFrequency = *max_element(frequency, frequency + 10);
	for (int i = 0; i < 10; i++)
	{
		intervalColumn->addItems(L"[" + to_wstring(i * increment) + L" ... " + to_wstring((i + 1) * increment) + L")");
		frequencyColumn->addItems(frequency[i]);
		graphColumn->addItems(wstring((frequency[i] / maxFrequency) * config::MAX_LENGTH_PIXEL, L'#'));
	}
	Table({ intervalColumn.get(), frequencyColumn.get(), graphColumn.get() }, L"").dumpTableTo(wcout);
}


void test1()
{
	long seed = rand();
	long multiplier = rand();
	long increment = rand();
	long modulus = rand();

	auto randomGenerator = RandomGenerator(seed, multiplier, increment, modulus);
	long firstRandom = randomGenerator.getRandomInt();
	long cycleLength = 0;
	do
		cycleLength++;
	while (randomGenerator.getRandomInt() != firstRandom);

	cout << "Test length cycle: " << endl;
	cout << "\t";
	diplayParameters(seed, multiplier, increment, modulus);
	cout << "Generated " << cycleLength << " different numbers" << endl;
}

void test2()
{
	cout << "Test Distribution: " << endl;
	cout << "\t";
	long seed = rand();
	long multiplier = rand();
	long increment = rand();
	long modulus = rand();

	//auto randomGenerator = RandomGenerator(seed, multiplier, increment, modulus);
	auto randomGenerator = RandomGenerator(1, 23959, 12982, 6389);
	auto incrementalDistribution = IncrementalDistribution();
	for (long long ll = 0; ll < 1000000; ll++)
	{
		incrementalDistribution.add(randomGenerator.getRandomInUnitInterval());
	}
	diplayParameters(seed, multiplier, increment, modulus);
	displayDistribution(incrementalDistribution.getDistribution());
}

void testGaussian()
{
	cout << "Test Gaussian Distribution: " << endl;
	cout << "\t";
	long seed = rand();
	long multiplier = rand();
	long increment = rand();
	long modulus = rand();

	const double defaultMedian = 0.5;
	const double defaultSd = 1;
	auto gaussianRandom = GaussianRandom(seed, multiplier, increment, modulus, defaultMedian, defaultSd);
	auto incrementalDistribution = IncrementalDistribution();
	for (long long ll = 0; ll < 1000000; ll++)
	{
		incrementalDistribution.add(gaussianRandom.getNextInGaussianDistribution());
	}
	diplayParameters(seed, multiplier, increment, modulus);
	cout << "Median = " << defaultMedian << ", Standard Deviation = " << defaultSd << endl;
	displayDistribution(incrementalDistribution.getDistribution());
}


void part2()
{
	test1();
	test2();
	testGaussian();
}

int main()
{
	srand(time(0));
	part2();
}
