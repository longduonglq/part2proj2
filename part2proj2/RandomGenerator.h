// Participants: Christopher, Duyen TRan
// Date: 02-28-21
// Description: Chapter 2 - Random Generator

#pragma once
#include <vector>

using namespace std;

class RandomGenerator
{
public:
	RandomGenerator() = default;
	// Person: Christopher
	//Precondition: need to pass in 4 long values
	//Postcondition: assigns values to seed, multiplier, increment, and modulus for calculating a psuedorandom number
	RandomGenerator(long _seed, long _multiplier, long _increment, long _modulus);
	
	// Person: Chrisopher
	//Precondition: need to pass in a long value
	//Postcondition: assigns value to seed
	void setSeed(long newSeed);

	// Person: Christopher
	//Precondition: seed, multiplier, increment, and modulus must be initialized
	//Postcondition: generates psuedorandom number using those 4 values and assigns seed this psuedorandom value
	long getRandomInt();

	// Person: DUYEN
	//Precondition: seed, multiplier, increment, and modulus must be initialized
	//Postcondition: Get a random double from [0, 1)
	double getRandomInUnitInterval();

private:
	long multiplier, increment, modulus;
	long long seed;
};
