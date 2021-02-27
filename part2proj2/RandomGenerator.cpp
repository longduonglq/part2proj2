// Participants: Christopher
// Date: 02-28-21
// Description: Chapter 2 - Random Generator

//Participants: Duyen TRan
//Date:02/26/2021
//Description: 2 last function.

#include <time.h>
#include "RandomGenerator.h"

#include<iostream>
#include<cstdlib>

using namespace std;

RandomGenerator::RandomGenerator(long _seed, long _multiplier, long _increment, long _modulus)
{
	seed = _seed;
	multiplier = _multiplier;
	increment = _increment;
	modulus = _modulus;
}

void RandomGenerator::setSeed(long newSeed)
{
	seed = newSeed;
}

long RandomGenerator::getRandomInt()
{
	return (multiplier * seed + increment) % modulus;
}

double RandomGenerator::getRandomInUnitInterval()
{
	srand(time(NULL));
	return (rand() / double(RAND_MAX)) / static_cast<double>(modulus);

}

void RandomGenerator::getRandomInGaussianDistribution()
{
	double median = 0.5;
	double sd; //standard deviation//I don't know how to find it so I just take the data from the user then I fix the data type of function to void.
	double sum = 0;

	cout << "Enter the standard deviation in (0..1]:  ";
	cin >> sd;

	for (int i = 0; i < 12; i++)
	{
		sum = sum + getRandomInUnitInterval();
	}

	cout << median + (sum - 6) * sd;
}
