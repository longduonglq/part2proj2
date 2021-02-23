#pragma once

// A class that calculates the distribution incrementally instead of relying on a vector
// contains all element
class IncrementalDistribution
{
public:
	// Person: Gia
	// Initialized internal array to 0
	IncrementalDistribution();
	
	// Person: Gia 
	void add(double newElement);

	// Person: Gia
	// Outputs the internal array for problem 13. So the first array element representing the range (0.0 ... 0.1) and so on ..  
	long* getDistribution();

private:
	long frequencies[10];
};
