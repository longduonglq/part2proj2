#pragma once
#include <vector>

using namespace std;

class RandomGenerator
{
public:
	// Person: Christopher
	// init class
	RandomGenerator(long _seed, long _multiplier, long _increment, long _modulus);
	
	// Person: Chrisopher
	// assign new seed
	void setSeed(long newSeed);

	// Person: Christopher
	// Get a new random Int from 0 to modulus (refer to problem 11 in textbook)
	long getRandomInt();

	// Person: DUYEN
	// Get a random double from [0, 1). (refer to 12 in textbook pg 94)
	double getRandomInUnitInterval();
	
	// Person: DUYEN
	// Get random number so that the distribution is Gaussian (refer to problem 14)
	// So I think the approach is to call getRandomInUnitInterval 12 times to generate 1 
	// random in Gaussian Distribution.
	double getRandomInGaussianDistribution();

private:
	long seed, multiplier, increment, modulus;
};
