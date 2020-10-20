#include "Machine.h"
#include "PlusOrMinus.h"
#include <iostream>

int main() {
	Machine m = Machine();
	std::cout << "Eulero's machine\n";
	std::cout << "Choose integer (0-400): ";
	int target;
	std::cin >> target;
	std::cout << "\nThere are " << m.countPartitionsOfInt(target) << " distinct ways to obtain "
		<< target << " as a sum of non-negative integers.";
}