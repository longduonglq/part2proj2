// Participants: Gia Minh Hoang
// Date: 02-28-21

//Participants: Long Duong
//Date:02-28-21

#include "IncrementalDistribution.h"
#include <numeric>

using namespace std;

/// Initialized internal array to all 0
IncrementalDistribution::IncrementalDistribution()
{
	fill(frequencies, frequencies + 10, 0);
}

void IncrementalDistribution::add(double newElement)
{
	const double increment = 0.1;
	for (int i = 0; i < 10; i++)
	{
		if (i * increment <= newElement && newElement < (i + 1) * increment)
		{
			frequencies[i] ++;
			break;
		}
	}
}

const long* IncrementalDistribution::getDistribution()
{
	return frequencies;
}
