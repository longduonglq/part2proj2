// Participants: Christopher
// Date: 02-28-21
// Description: Chapter 2 - Random Generator
#include <time.h> 
#include "RandomGenerator.h"

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

}

double RandomGenerator::getRandomInGaussianDistribution()
{

}
