#include "GaussianRandom.h"

GaussianRandom::GaussianRandom(long seed, long multiplier, long increment, long modulus, double _median, double _sd)
{
	median = _median;
	sd = _sd;
	randomGenerator = RandomGenerator(seed, multiplier, increment, modulus);
}

double GaussianRandom::getNextInGaussianDistribution()
{
	double sum = 0;
	for (int i = 0; i < 12; i++)
	{
		sum = sum + randomGenerator.getRandomInUnitInterval();
	}
	return median + (sum - 6) * sd;
}