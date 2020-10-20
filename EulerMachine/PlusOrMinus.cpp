#include "PlusOrMinus.h"

//constructor
PlusOrMinus::PlusOrMinus(int _position, int _isPlus): position(_position), isPlus(_isPlus) {}

//getters
int PlusOrMinus::getPosition() {return position;}
int PlusOrMinus::getSign() { return isPlus ? 1 : -1; }
int PlusOrMinus::getIsPlus() { return isPlus; }
