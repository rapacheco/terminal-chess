#ifndef _TILE_H_
#define _TILE_H_

#include <iostream>

#include "Tuple.h"

namespace chess {

	// TRANSLATION FOR PIECES:
	// pawn = 'p'
	// bishop = 'b'
	// knight = 'k'
	// rook = 'r'
	// queen = 'q'
	// king = 'K'


	// class to represent each tile of the chessboard
	class Tile {
		Tuple _tup; // a tuple to represent the tile's coordinates
		char _value; // the piece that is on it
		bool _white; // whether is a white or a black piece
	public:
		Tile() : _tup(), _value(' '), _white(false) {}; // empty safe state {(-1, -1), ' ', false}
		Tile(short int x, short int y) : _value(' '), _white(false) {
			if (x < 0 || y < 0) {
				_tup = Tuple(x, y);
			}
			else _tup = Tuple();
		} // initialize only the coordinates
		Tile(short int x, short int y, char value) { 
			Tile::Tile(x, y);
			if (_value != 'p' && _value != 'b' && _value != 'k'
				&& _value != 'r' && _value != 'q' && _value != 'K') {
				_tup = Tuple();
				_value = ' ';
			}
			else _value = value;
		} // sets the coordinates and the piece
		Tile(short int x, short int y, char value, bool white) {
			Tile::Tile(x, y, value);
			_white = white;
		} // full constructor
		int x() const; 
		int y() const;
		char value() const;
		void set(const char value, bool white = false);
		bool isWhite() const;
		void display(std::ostream&) const
		
	};

	std::ostream& operator<<(std::ostream&, const Tile&);

}

#endif
