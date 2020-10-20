#include "Machine.h"
#include "PlusOrMinus.h"
#include <iostream>

//constructor
Machine::Machine():counter(1), nextSign(PlusOrMinus(1, true)) {
	outputs.push_back(1);
	signs.push_back(PlusOrMinus(0, true));
}

//produces the next output of the machine
void Machine::nextOutput() {
	unsigned long long tot = 0;
	for (PlusOrMinus sign : signs) {
		//add/subtract all the numbers alligned with a sign
		tot += sign.getSign() * outputs[counter - sign.getPosition() - 1];
	}
	outputs.push_back(tot);
	if (nextSign.getPosition() == counter) //nextSign will be needed on the next iteration
		addNextSign();
	counter++;
}

//push nextSign into the signs list and compute new nextSign
void Machine::addNextSign() {
	signs.push_back(nextSign);
	int length = signs.size();
	//each sign has a position in the bottom sign belt of the machine
	//the sequence of the position of the signs is: 0, 1, 4, 6, 11, 14, 21...
	//we define sequence of the increments as the sequence of the differences in position between consecutive signs
	//sequence of the increments: 1, 3, 2, 5, 3, 7...
	if (length % 2 == 0) {
		if (length == 2)
			nextSign = PlusOrMinus(4, false);
		else
			nextSign = PlusOrMinus(
				//given the sequence of the increments, the subsequence of 2nd, 4th, 6th... terms is:
				//3, 5, 7, 9, 11...
				signs[length - 1].getPosition()
				+ signs[length - 2].getPosition() - signs[length - 3].getPosition()
				+ 2,//the terms of the subsequence differ by 2
				!signs[length - 1].getIsPlus()
			);
	}
	else {
		nextSign = PlusOrMinus(
			//given the sequence of the increments, the subsequence of 2nd, 4th, 6th... terms is:
			//1, 2, 3, 4, 5...
			signs[length - 1].getPosition()
			+ signs[length - 2].getPosition() - signs[length - 3].getPosition()
			+ 1,//the terms of the subsequence differ by 1
			signs[length - 1].getIsPlus()
		);
	}
}

unsigned long long Machine::countPartitionsOfInt(int n) {
	if (n < 0)
		return -1;
	else if (n == 0)
		return 1;
	else
	{
		while (counter <= n)
			nextOutput();
	}
	return outputs[counter - 1];
}
