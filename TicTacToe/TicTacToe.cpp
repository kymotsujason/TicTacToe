// TicTacToe.cpp
// TicTacToe AI creation attempt (computerMove() function)

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct tictactoe {
	vector<vector<int>> board;
	vector<int> player;
};

tictactoe initBoard(tictactoe game, int size) {
	game.board.resize(size);
	for (int i = 0; i < size; i++) {
		game.board[i].resize(size);
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			game.board[i][j] = -1;
		}
	}
	return game;
}

void displayBoard(tictactoe game) {
	cout << endl;
	for (int i = 0; i < game.board.size(); i++) {
		for (int j = 0; j < game.board.size(); j++) {
			if (j < game.board.size() - 1) {
				if (game.board[i][j] == -1) {
					cout << "  " << " | ";
				}
				else {
					cout << game.board[i][j] << " | ";
				}
			}
			else {
				if (game.board[i][j] == -1) {
					cout << "  " << endl;
				}
				else {
					cout << game.board[i][j] << endl;
				}
			}
		}
		for (int k = 0; k < game.board.size(); k++) {
			if (i < game.board.size() - 1) {
				cout << "----";
			}
		}
		if (i < game.board.size() - 1) {
			cout << endl;
		}
	}
	cout << endl;
}

tictactoe loadPlayers(tictactoe game, int tmp, int order) {
	if (order == 0) {
		game.player.resize(tmp);
		for (int i = 0; i < game.player.size(); i++) {
			game.player[i] = i + 1;
		}
	}
	else if (order == 1) {
		game.player.resize(tmp + 1);
		for (int i = 0; i < game.player.size(); i++) {
			if (i == 0) {
				game.player[i] = i + 1;
			}
			else {
				game.player[i] = 0;
			}
		}
	}
	else {
		game.player.resize(tmp + 1);
		for (int i = 0; i < game.player.size(); i++) {
			if (i < game.player.size() - 1) {
				game.player[i] = 0;
			}
			else {
				game.player[i] = i + 1;
			}
		}
	}
	return game;
}

bool checkWin(tictactoe game) {
	for (int i = 0; i < game.board.size(); i++) {
		vector<int> horizontal;
		bool win = true;
		for (int j = 0; j < game.board.size(); j++) {
			horizontal.push_back(game.board[i][j]);
		}
		for (int j = 0; j < horizontal.size(); j++) {
			for (int k = 0; k < horizontal.size(); k++) {
				if (horizontal[j] != horizontal[k] || horizontal[j] == -1 || horizontal[k] == -1) {
					win = false;
				}
			}
		}
		if (win) {
			return true;
		}
	}
	for (int i = 0; i < game.board.size(); i++) {
		vector<int> vertical;
		bool win = true;
		for (int j = 0; j < game.board.size(); j++) {
			vertical.push_back(game.board[j][i]);
		}
		for (int j = 0; j < vertical.size(); j++) {
			for (int k = 0; k < vertical.size(); k++) {
				if (vertical[j] != vertical[k] || vertical[j] == -1 || vertical[k] == -1) {
					win = false;
				}
			}
		}
		if (win) {
			return true;
		}
	}
	for (int i = 0; i < 2; i++) {
		vector<int> diagonal;
		bool win = true;
		if (i == 0) {
			for (int j = 0; j < game.board.size(); j++) {
				diagonal.push_back(game.board[j][j]);
			}
		}
		else if (i == 1) {
			int col = 0;
			for (int j = (int)game.board.size() - 1; j >= 0; j--) {
				diagonal.push_back(game.board[j][col]);
				col++;
			}
		}
		for (int j = 0; j < diagonal.size(); j++) {
			for (int k = 0; k < diagonal.size(); k++) {
				if (diagonal[j] != diagonal[k] || diagonal[j] == -1 || diagonal[k] == -1) {
					win = false;
				}
			}
		}
		if (win) {
			return true;
		}
	}
	return false;
}

int checkForWinner(tictactoe game) {
	for (int i = 0; i < game.board.size(); i++) {
		vector<int> horizontal;
		bool win = true;
		for (int j = 0; j < game.board.size(); j++) {
			horizontal.push_back(game.board[i][j]);
		}
		for (int j = 0; j < horizontal.size(); j++) {
			for (int k = 0; k < horizontal.size(); k++) {
				if (horizontal[j] != horizontal[k] || horizontal[j] == -1 || horizontal[k] == -1) {
					win = false;
				}
			}
		}
		if (win) {
			return horizontal[0];
		}
	}
	for (int i = 0; i < game.board.size(); i++) {
		vector<int> vertical;
		bool win = true;
		for (int j = 0; j < game.board.size(); j++) {
			vertical.push_back(game.board[j][i]);
		}
		for (int j = 0; j < vertical.size(); j++) {
			for (int k = 0; k < vertical.size(); k++) {
				if (vertical[j] != vertical[k] || vertical[j] == -1 || vertical[k] == -1) {
					win = false;
				}
			}
		}
		if (win) {
			return vertical[0];
		}
	}
	for (int i = 0; i < 2; i++) {
		vector<int> diagonal;
		bool win = true;
		if (i == 0) {
			for (int j = 0; j < game.board.size(); j++) {
				diagonal.push_back(game.board[j][j]);
			}
		}
		else if (i == 1) {
			int col = 0;
			for (int j = (int)game.board.size() - 1; j >= 0; j--) {
				diagonal.push_back(game.board[j][col]);
				col++;
			}
		}
		for (int j = 0; j < diagonal.size(); j++) {
			for (int k = 0; k < diagonal.size(); k++) {
				if (diagonal[j] != diagonal[k] || diagonal[j] == -1 || diagonal[k] == -1) {
					win = false;
				}
			}
		}
		if (win) {
			return diagonal[0];
		}
	}
	return -1;
}

int bruteForce(tictactoe game, int player1, int player2);

int cpuMove(tictactoe game, int player1, int player2) {
	int best_overall_score = -9999;
	int best_row_score = -9999;
	int best_col_score = -9999;
	int current_score = 0;

	for (int i = 0; i < game.board.size(); i++) {
		for (int j = 0; j < game.board.size(); j++) {
			if (game.board[i][j] == -1) {
				// simulation
				game.board[i][j] = player1;
				current_score = -(bruteForce(game, player2, player1));
				// undo for finishing recursion
				game.board[i][j] = -1;
				if (current_score >= best_overall_score) {
					best_overall_score = current_score;
					best_row_score = i;
					best_col_score = j;
				}
			}
		}
	}

	return (10 * best_row_score + best_col_score);
}

int bruteForce(tictactoe game, int player1, int player2) {
	int best_overall_score = -9999;
	int current_score = 0;

	if (checkForWinner(game) == player1) {
		return 1000;
	}
	else if (checkForWinner(game) == player2) {
		return -1000;
	}
	
	for (int i = 0; i < game.board.size(); i++) {
		for (int j = 0; j < game.board.size(); j++) {
			if (game.board[i][j] == -1) {
				// simulation
				game.board[i][j] = player1;
				current_score = -(bruteForce(game, player2, player1));
				// undo for finishing recursion
				game.board[i][j] = -1;
				if (current_score >= best_overall_score) {
					best_overall_score = current_score;
				}
			}
		}
	}

	if (best_overall_score == -9999 || current_score == 0) {
		return 0;
	}
	else if (best_overall_score < 0) {
		return best_overall_score + 1;
	}
	else if (best_overall_score > 0) {
		return best_overall_score - 1;
	}
}

int playerMove(tictactoe game) {
	int row, col;
	int maximum = game.board.size() * game.board.size();
	int moves = 0;
	bool CPUwin = false;
	bool playerWin = false;
	while (moves < maximum && !CPUwin && !playerWin) {
		for (int i = 0; i < game.player.size(); i++) {
			if (game.player[i] != 0 && moves < maximum && !CPUwin && !playerWin) {
				cout << "Player " << i + 1 << "'s turn, enter a row (1-" << game.board.size() << "): " << endl;
				cin >> row;
				cout << "Player " << i + 1 << "'s turn, enter a col (1-" << game.board.size() << "): " << endl;
				cin >> col;
				game.board[row - 1][col - 1] = i + 1;
				moves++;
				displayBoard(game);
				if (checkWin(game)) {
					int winner = checkForWinner(game);
					if (winner == 0) {
						cout << "The CPU has won the game =P" << endl;
						CPUwin = true;
					}
					else {
						cout << "Player " << winner << " has won the game!" << endl;
						playerWin = true;
					}
				}
			}
			else if (moves < maximum && !CPUwin && !playerWin) {
				if (game.player.size() == 2) {
					int player1 = 0;
					int player2 = 1;
					cout << "CPU is now thinking..." << endl;
					int bestMove = cpuMove(game, player1, player2);
					int cpuRow = bestMove / 10;
					int cpuCol = bestMove % 10;
					cout << "CPU is now moving..." << endl;
					game.board[cpuRow][cpuCol] = 0;
					moves++;
					cout << "CPU has moved!" << endl;
					displayBoard(game);
					if (checkWin(game)) {
						int winner = checkForWinner(game);
						if (winner == 0) {
							cout << "The CPU has won the game =P" << endl;
							CPUwin = true;
						}
						else {
							cout << "Player " << winner << " has won the game!" << endl;
							playerWin = true;
						}
					}
				}
				else {
					//something for multiplay
				}
			}
		}
	}
	if (moves >= maximum) {
		cout << "Tie! Better luck next time =P" << endl;
	}
	if (CPUwin) {
		return 0;
	}
	else if (moves >= maximum) {
		return 2;
	}
	else {
		return 1;
	}
}

int main()
{
	string userInput;
	int tmp;
	int wins = 0;
	int ties = 0;
	int loss = 0;
	cout << "Welcome to TicTacToe! Type 'start' to begin or 'stats' to view your statistics or 'exit' to quit: " << endl;
	while (userInput != "exit") {
		cin >> userInput;

		if (userInput == "start" || userInput == "s") {
			tictactoe game;
			cout << "How many players will be playing (whole number): " << endl;
			cin >> tmp;
			if (tmp > 1) {
				cout << "Would you like the CPU to join you (y/n): " << endl;
				cin >> userInput;
				if (userInput != "y") {
					int order = 0;
					game = loadPlayers(game, tmp, order);
				}
				else {
					cout << "Do you want the players to go first or after the CPU (1/2): " << endl;
					int order;
					cin >> order;
					game = loadPlayers(game, tmp, order);
				}
			}
			else {
				cout << "The CPU will be your opponent, would you like to go first or second (1/2): " << endl;
				int order;
				cin >> order;
				game = loadPlayers(game, tmp, order);
			}
			cout << tmp << " player(s) loaded!" << endl;
			cout << "Would you like a standard board or a custom size board (enter 'standard' or 'custom'): " << endl;
			cin >> userInput;
			if (userInput == "standard" || userInput == "s") {
				tmp = 3;
				game = initBoard(game, tmp);
			}
			else if (userInput == "custom" || userInput == "c") {
				cout << "Enter a custom size you'd like (will generate a square with your input): " << endl;
				cin >> tmp;
				game = initBoard(game, tmp);
			}
			else {
				cout << "Unknown input... you entered " << userInput << endl;
				break;
			}
			cout << "The game has been set, here's the board!" << endl;
			displayBoard(game);
			int results = playerMove(game);
			if (results == 0) {
				loss++;
			}
			else if (results == 1) {
				wins++;
			}
			else if (results == 2) {
				ties++;
			}
			cout << "You now have: " << wins << " game(s) won, " << ties << " game(s) tied, " << loss << " game(s) lost" << endl;
		}

		if (userInput == "stats") {
			cout << "You currently have: " << wins << " game(s) won, " << ties << " game(s) tied, " << loss << " game(s) lost" << endl;
		}

		cout << "Welcome to TicTacToe! Type 'start' to begin or 'stats' to view your statistics or 'exit' to quit: " << endl;
	}
	return 0;
}