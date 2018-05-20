#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>

#include "Tile.h"
#include "Tuple.h"

namespace chess {

	const int LENGTH = 8; // length of the board
	const int NUM = 16; // maximum number of possible plays

	// TRANSLATION FOR PIECES:
	// pawn = 'p'
	// bishop = 'b'
	// knight = 'k'
	// rook = 'r'
	// queen = 'q'
	// king = 'K'

	// class to represent the chessboard and to execute the logic of the piece's movements
	class Board {

		Tile _tiles[LENGTH][LENGTH]; // board is a collection of tiles 8x8
		Tuple _possib[NUM]; // array to store possible movements
		bool _white; // whether is white's or black's turn

	public:

		Board() : _white(true) {
			for (int i = 0; i < LENGTH; i++) {
				for (int j = 0; j < LENGTH; j++) {
					_tiles[i][j] = Tile(i, j);
				}
			}
			for (int i = 0; i < NUM; i++) {
				_possib[i] = Tuple();
			}
			// initial state of the game. White starts
		}
		void set();
		void reset();
		void display(std::ostream&) const;
		bool isEmpty(Tuple) const;
		bool isWhite(Tuple) const;
		bool whiteTurn() const;
		void changePlayer();
		void setNull();
		void checkMove(const Tuple);
		bool move(const Tuple, const Tuple);
		
	};

	std::ostream& operator<<(std::ostream& os, const Board& board);

}

#endif
