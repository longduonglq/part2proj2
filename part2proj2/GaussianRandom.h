#pragma once
#include "RandomGenerator.h"

class GaussianRandom
{
public:
	GaussianRandom(long seed, long multiplier, long increment, long modulus, double _median, double _sd);
	double getNextInGaussianDistribution();

private:
	double median, sd;
	RandomGenerator randomGenerator;
};
