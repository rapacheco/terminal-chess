#ifndef _TUPLE_H_
#define _TUPLE_H_

#include <iostream>

namespace chess {

	// simple class to store a value of two integers (x, y)
	class Tuple {
		int _x;
		int _y;
	public:
		Tuple() : _x(-1), _y(-1) {} // empty safe state is (-1, -1)
		Tuple(int x, int y) : _x(x), _y(y) {} // constructor with 2 arguments
		int x() const { return _x; } // getter for x
		int y() const { return _y; } // getter for y
		bool isInvalid() const { return _x < 0 || _y < 0; } // query empty safe state
		void display(std::ostream& os) const {
			os << "(" << _x << ", " << _y << ")";
		} // display formated tuple into ostream object
		bool operator==(Tuple tup) {
			return _x == tup._x && _y == tup._y;
		} // compares two tuples
		
	};
}

#endif