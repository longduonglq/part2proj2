// Participants: Christopher
// Date: 02-28-21
// Description: Chapter 2 - Random Generator
#include <time.h> 
#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(long seed, long multiplier, long increment, long modulus)
{
	//buffer
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
