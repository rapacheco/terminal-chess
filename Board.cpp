#include <iostream>

#include "Board.h"
#include "Tile.h"
#include "Tuple.h"

namespace chess {

	// set the initial arrangement of the game
	void Board::set() {
		char first[LENGTH] = { 'r', 'k', 'b', 'q', 'K', 'b', 'k', 'r' };
		for (int j = 0; j < LENGTH; j++) {
			_tiles[0][j].set(first[j]);
			_tiles[7][j].set(first[j], true);
			_tiles[1][j].set('p');
			_tiles[6][j].set('p', true);
		}
	}

	// resets the game
	void Board::reset() {
		Board::Board();
	}

	// draws the board into standard output
	void Board::display(std::ostream& os) const {
		int count = 8;
		for (int i = 0; i < LENGTH; i++) {
			os << "  ---------------------------------" << '\n' << count << " ";
			for (int j = 0; j < LENGTH; j++) {
				os << "|";
				
				// if a piece is white, prefix it with 'w'
				if (_tiles[i][j].isWhite()) os << "w";
				else os << " ";
				
				// draws the pieces
				os << _tiles[i][j];
				
				// when a piece is selected, a '<' indicates the possibles movements
				char ind = ' ';
				int count = 0;
				while (_possib[count].x() != -1) {
					if (_possib[count].x() == j && _possib[count].y() == i) {
						ind = '<';
					}
					count++;
				}
				os << ind;
			}
			os << "|" << '\n';
			count--;
		}
		os << "  ---------------------------------" << '\n';
		os << "    A   B   C   D   E   F   G   H  " << '\n';
	}

	// checks if a given tile is empty
	bool Board::isEmpty(Tuple tup) const {
		return _tiles[tup.y()][tup.x()].value() == ' ';
	}

	// checks if there is a white piece on a given tile
	bool Board::isWhite(Tuple tup) const {
		return _tiles[tup.y()][tup.x()].isWhite();
	}

	// checks if it is the white's turn
	bool Board::whiteTurn() const {
		return _white;
	}

	// changes the current player
	void Board::changePlayer() {
		_white = !_white;
	}

	// erases the array of possible movements
	void Board::setNull() {
		_possib[0] = Tuple();
	}

	// loads the array of possible movements with the possible
	// movements of the selected piece
	void Board::checkMove(Tuple tup) {
		char value = _tiles[tup.y()][tup.x()].value();
		bool white = _tiles[tup.y()][tup.x()].isWhite();
		int counter = 0;
		
		switch (value) {
		
		// logic for the pawn's movement
		case 'p':
			int a, b, c;
			if (white) 	a = 6, b = -2, c = -1;
			else a = 1, b = 2, c = 1;
			
			if (tup.y() == a) {
				_possib[counter] = Tuple(tup.x(), tup.y() + b);
				counter++;
			}
			_possib[counter] = Tuple(tup.x(), tup.y() + c);
			counter++;
			
			while (counter < NUM) {
				_possib[counter] = Tuple(-1, -1);
				counter++;
			}
			break;

		// if selected tile is empty
		default:
			_possib[0] = Tuple();
		}

	}

	// after checking if destination is possible, moves piece (sel) to 
	// destination (dest)
	bool Board::move(Tuple sel, Tuple dest) {
		bool possible = false;
		for (int i = 0; i < NUM; i++) {
			if (dest == _possib[i])
				possible = true;
		}
		if (possible) {
			_tiles[dest.y()][dest.x()].set(_tiles[sel.y()][sel.x()].value(), _tiles[sel.y()][sel.x()].isWhite());
			_tiles[sel.y()][sel.x()].set(' ');
		}
		return possible;
	}

	// operator to concatenate boards output
	std::ostream& operator<<(std::ostream& os, const Board& board) {
		board.display(os);
		return os;
	}

}