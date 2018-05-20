#include <iostream>

#include "Tile.h"

namespace chess {

	// getter for coordinate x
	int Tile::x() const {
		return _tup.x();
	}

	// getter for coordinate y
	int Tile::y() const {
		return _tup.y();
	}

	// getter for the tile's piece
	char Tile::value() const {
		return _value;
	}

	// sets the piece into the tile (white or black)
	void Tile::set(const char value, bool white) {
		if (value == 'p' || value == 'b' || value == 'k'
			|| value == 'r' || value == 'q' || value == 'K')
			_value = value;
		else _value = ' ';
		_white = white;
	}

	// query if there's a white piece on the tile
	bool Tile::isWhite() const {
		return _white;
	}

	// display the piece on the ostream object
	void Tile::display(std::ostream& os) const {
		os << _value;
	}

	// operator to concatenate the tile's output
	std::ostream& operator<<(std::ostream& os, const Tile& tile) {
		tile.display(os);
		return os;
	}

}