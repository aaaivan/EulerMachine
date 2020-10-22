#pragma once

class PlusOrMinus
{
private:
	int position; //position of the sign in the sign ribbon
	bool isPlus;
public:
	PlusOrMinus(int _position, int _isPlus);
	int getPosition();
	int getSign();
	int getIsPlus();
};

