#include <iostream>

#include "Tile.h"
#include "Board.h"
#include "Tuple.h"

using namespace chess;
using namespace std;

Tuple input(const char*, bool);
Tuple selectMove(bool);
Tuple options(bool);

bool selected = false;

int main() {

	Board board;
	Tuple select, dest;
	board.set();

	while (1) {
		cout << board << '\n' << endl;

		if (!selected) {
			select = selectMove(board.whiteTurn());
			if (select.isInvalid());
			else if (board.isEmpty(select)) 
				cout << " *** The space selected is empty ***" << endl;
			else if (board.isWhite(select) != board.whiteTurn())
				cout << " *** You selected your oponent's piece ***" << endl;
			else {
				board.checkMove(select);
				selected = true;
			}
		}
		else {
			dest = options(board.whiteTurn());
			if (dest.isInvalid()) {
				board.setNull();
				selected = false;
			}
			else {
				if (board.move(select, dest)) {
					board.setNull();
					board.changePlayer();
					selected = false;
				}
				else cout << "*** Invalid destination ***" << endl;

			}
		}
	}
	
	std::cin.get();

	return 0;

}

Tuple input(const char* str, bool white) {
	char x, y;
	bool cancel = false;
	Tuple temp;
	
	while (1) {
		if (white) cout << "<WHITE> ";
		else cout << "<BLACK> ";
		cout << str;
		cin >> x >> y;
		cin.ignore(2000, '\n');
		cout << endl;

		if (x == 'c' && y == 'a') {
			cancel = true;
			break;
		}

		if (!cancel) {

			if ((x < 65 || (x > 72 && x < 97) || x > 104) ||
				(y < 49 || y > 56)) {
				cout << "*** Wrong input - range (a-h, 1-8) ***" << '\n' << endl;
			}
			else {
				if (x >= 65 && x <= 72)
					x += 32;
				temp = Tuple((int)x - 97, 7 - (y - 49));
				break;
			}
		}
	}		
	return temp;
}

Tuple selectMove(bool white) {
	Tuple temp = input("Select piece (<row><col>): ", white);
	
	return temp;
}

Tuple options(bool white) {
	Tuple result = input("Type destination (<row><col>) or 'cancel' to go back: ", white);

	return result;

}