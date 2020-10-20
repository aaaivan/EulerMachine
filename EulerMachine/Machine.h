#pragma once
#include "PlusOrMinus.h"
#include <vector>

class Machine
{
private:
	int counter; //increases by 1 every time an aoutput is prodeuced
	std::vector<unsigned long long> outputs; //n-th element = output of the machine when counter=n
	std::vector<PlusOrMinus> signs;
	PlusOrMinus nextSign; //next sign to be placed into signs
public:
	Machine();
	void nextOutput();
	void addNextSign();
	unsigned long long countPartitionsOfInt(int n);
};

