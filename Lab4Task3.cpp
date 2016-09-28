//Tic Tac Toe Program

//Usual Headers
#include <iostream>
using namespace std;

//Declaring Constant Variables
const int NUM_ROWS = 3;
const int NUM_COLUMNS = 3;
char game[NUM_ROWS][NUM_COLUMNS];
char PlayerOne;
char PlayerTwo;

//Function to Draw the board (To be called after every move)
void BoardDraw() {

	cout << endl;
	cout << "     Col 1 Col 2 Col 3" << endl;
	cout << "          |     |     " << endl;
	cout << "Row 1  " << game[0][0] << "  |  " << game[0][1] << "  |  " << game[0][2] << endl;
	cout << "     _____|_____|_____" << endl;
	cout << "          |     |     " << endl;
	cout << "Row 2  " << game[1][0] << "  |  " << game[1][1] << "  |  " << game[1][2] << endl;
	cout << "     _____|_____|_____" << endl;
	cout << "          |     |     " << endl;
	cout << "Row 3  " << game[2][0] << "  |  " << game[2][1] << "  |  " << game[2][2] << endl;
	cout << "          |     |     " << endl << endl;

}

//Function to Check for a winner in the game board (Layout and help from http://stackoverflow.com/questions/16328404/tic-tac-toe-game-2d-array)
char CheckWinner(char game[][3]) {

	for (int check1 = 0; check1 < 3; check1++) {
		if (game[check1][0] == game[check1][1] && game[check1][0] == game[check1][2]) { //Horizontal Check
			return game[check1][0];
		}
	}
	for (int check2 = 0; check2 < 3; check2++) {
		if (game[0][check2] == game[1][check2] && game[0][check2] == game[2][check2]) { //Vertical Check
			return game[0][check2];
		}
	}
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2]) { //Diagonal Check #1
		return game[0][0];
	}
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0]) { //Diagonal Check #2
		return game[0][2];
	}
	return ' ';
}

//Main Program
int main() {

	//Start/Initialisation Screen
	cout << "Tic Tac Toe - by Adam Jackson (Format from http://cppforschool.com/project/tic-tac-toe-project.html)";
	cout << "With help from the code on: http://stackoverflow.com/questions/16328404/tic-tac-toe-game-2d-array";
	cout << endl;
	cout << endl;
	cout << "Player 1 (X)	-	Player 2 (O)" << endl << endl;
	
	//Filling all cells with spaces
	for (int row = 0; row < NUM_ROWS; row++) {

		for (int column = 0; column < NUM_COLUMNS; column++) {

			game[row][column] = ' ';
		
		}

	}

	//First sketch of the board
	BoardDraw();

	//Initialising local variables
	bool Win = false;
	int RowNum = 0;
	int ColNum = 0;
	bool error = true;
	int TieCount = 0;
	char winner = ' ';

	//Do this code whilst a winner (or tie) hasn't been found
	while (Win == false) {

		//Checking for a winner in the board
		winner = CheckWinner(game);
		cout << "here2" << winner << endl;
		if (winner == 'X' || winner == 'O') {
			BoardDraw();
			cout << "The Winner is Letter " << winner << endl;
			Win = true;
			break; //Break takes us right out of the program as Win is now set to true
		}
		
		//Error checks for attempting to place in a used box
		error = true;
		while (error == true) {
			cout << "Player One, Please enter the Row Number: " << endl;
			cin >> RowNum;
			cout << "And now your Column Number: " << endl;
			cin >> ColNum;
			if (game[RowNum - 1][ColNum - 1] == ' ') {
				game[RowNum - 1][ColNum - 1] = 'X';
				BoardDraw();
				error = false; //Breaking out of the while loop
			}
			else {
				cout << "Invalid Placement" << endl; //After this it loops around to try again
			}
		}
		
		//Check if the previous move was a winning one
		winner = CheckWinner(game);
		if (winner == 'X' || winner == 'O') {
			BoardDraw();
			cout << "The Winner is Letter " << winner << endl;
			Win = true;
			break;
		}

		//After 9 moves the game board will be full e.g. a tie so this will check how many moves have been taken
		TieCount = TieCount + 1;
		if (TieCount == 9) {
			BoardDraw();
			cout << "It's A Tie!!!" << endl;
			Win = true;
			break;
		}

		//Player 2's Turn
		error = true;
		while (error == true) {
			cout << "Player Two, Please enter the Row Number: " << endl;
			cin >> RowNum;
			cout << "And now your Colum Number: " << endl;
			cin >> ColNum;
			if (game[RowNum - 1][ColNum - 1] == ' ') {
				game[RowNum - 1][ColNum - 1] = 'O';
				BoardDraw();
				error = false;
			}
			else {
				cout << "Invalid Placement" << endl;
			}
		}
		//Counting Player 2's turn
		TieCount = TieCount + 1;
	}
	return 0;
}