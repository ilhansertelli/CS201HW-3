#include <iostream>
#include <string>
#include <vector>
using namespace std;

void gamePlayer(string name1, string symbol1, string name2, string symbol2, int & score1, int & score2);
void playerMove(string name,	string symbol, string & move);
void print(vector<vector<string>> & b);
bool formatCheck(string a);
bool winner(vector<vector<string>> b, string s1);

void gamePlayer(string name1, string symbol1, string name2, string symbol2, int & score1, int & score2) {
	string move, s1 = "X", s2 = "O";
	int idx1, idx2;
	vector<vector<string>> matrix(3, vector<string>(3, " "));
	for (int c = 0; c < 5; c++) {
		cout << name1 << ", please enter your move: ";
		cin >> move;

		playerMove(name1, symbol1, move);
		idx1 = char(move.at(0));
		idx2 = char(move.at(2));
		while (matrix[idx1 - 49][idx2 - 49] != " ") {
			cout << "That location is already full!" << endl;
			cout << name1 << ", please enter your move: ";
			cin >> move;
			while (formatCheck(move) == false) {
			cout << "Please enter correct move format!" << endl;
			cout << name1 << ", please enter your move: ";
			cin >> move;
			}
			idx1 = char(move.at(0));
			idx2 = char(move.at(2));
		}
		matrix[idx1 - 49][idx2 - 49] = symbol1;
		if (winner(matrix, symbol1) == true) {
			score1++;
			break;
		}
		if ((matrix[0][0] != " ") && (matrix[0][1] != " ") && (matrix[0][2] != " ") &&
			(matrix[1][0] != " ") && (matrix[1][1] != " ") && (matrix[1][2] != " ") &&
			(matrix[2][0] != " ") && (matrix[2][1] != " ") && (matrix[2][2] != " ")) {
			
			break;
		}
		
		print(matrix);

		cout << name2 << ", please enter your move: ";
		cin >> move;

		playerMove(name2, symbol2, move);
		idx1 = char(move.at(0));
		idx2 = char(move.at(2)); 
		while (matrix[idx1 - 49][idx2 - 49] != " ") {
			cout << "That location is already full!" << endl;
			cout << name2 << ", please enter your move: ";
			cin >> move;
			while (formatCheck(move) == false) {
			cout << "Please enter correct move format!" << endl;
			cout << name2 << ", please enter your move: ";
			cin >> move;
			}
			idx1 = char(move.at(0));
			idx2 = char(move.at(2));
		}
		matrix[idx1 - 49][idx2 - 49] = symbol2;
		if (winner(matrix, symbol2) == true) {
			score2++;
			break;
		} 
		print(matrix);
	}
}

void playerMove(string name, string symbol, string & move) {
	while (formatCheck(move) == false) {
		cout << "Please enter correct move format!" << endl;
		cout << name << ", please enter your move: ";
		cin >> move;
	}
} 

bool winner(vector<vector<string>> b, string s1) {
	if (((b[0][0] == s1) && (b[0][1] == s1) && (b[0][2] == s1)) ||
		((b[1][0] == s1) && (b[1][1] == s1) && (b[1][2] == s1)) ||
		((b[2][0] == s1) && (b[2][1] == s1) && (b[2][2] == s1)) ||
		((b[0][0] == s1) && (b[1][1] == s1) && (b[2][2] == s1)) ||
		((b[2][0] == s1) && (b[1][1] == s1) && (b[0][2] == s1)) ||
		((b[0][0] == s1) && (b[1][0] == s1) && (b[2][0] == s1)) ||
		((b[0][1] == s1) && (b[1][1] == s1) && (b[2][1] == s1)) ||
		((b[0][2] == s1) && (b[1][2] == s1) && (b[2][2] == s1))) {
		return true;
	}

	return false;
}

bool formatCheck(string a) {
	if (a.length() == 3) {
		if ((a.at(0) != '1') && (a.at(0) != '2') && (a.at(0) != '3')) {
			return false;
		}
		else {
			if (a.at(1) != '-') {
				return false;
			}
			else {
				if ((a.at(2) != '1') && (a.at(2) != '2') && (a.at(2) != '3')) {
					return false;
				}
				else {
					return true;
				}
			}
		}
	}
	else {
		return false;
	}
}

void print(vector<vector<string>> & b) {
	cout << "Current board: " << endl;
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			if ((j == 0) || (j == 1)) {
				cout << " " << b[i][j] << " " << "|";
			}
			else {
				cout << " " << b[i][j] << endl;
			}
		}
		if ((i == 0) || (i == 1)) {
			cout << "-----------" << endl;
		}
	}
}

int main() {
	string name1, name2, move, winner, loser;
	string symbol1 = "X", symbol2 = "O";
	int score1 = 0, score2 = 0;
	vector<vector<string>> matrix(3, vector<string>(3, " "));

	cout << "Welcome to Tic-Tac-Toe!" << endl;
	cout << "Player 1, please enter your name: ";
	cin >> name1;

	cout << "Hello, " << name1 << ". You are going to play with X" << endl;
	cout << "Player 2, please enter your name: ";
	cin >> name2;
	cout << "Hello, " << name2 << ". You are going to play with O" << endl;
	cout << endl;

	cout << "Starting a new game..." << endl;
	print(matrix);
	gamePlayer(name1, symbol1, name2, symbol2, score1, score2);

	if (score1 == 0 && score2 == 0) {
		cout << "The game ended in a draw!" << endl;
		cout << "Current Scores: " << endl;
		cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		cout << "Starting a new game..." << endl;
		print(matrix);
		gamePlayer(name2, symbol2, name1, symbol1, score2, score1);
		if (score1 == 1 && score2 == 0) {
			cout << name1 << " is the winner!" << endl;
			cout << "Current Scores: " << endl;
			cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		}
		else if (score1 == 0 && score2 == 1) {
			cout << name2 << " is the winner!" << endl;
			cout << "Current Scores: " << endl;
			cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		}
		else if (score1 == 0 && score2 == 0) {
			cout << "The game ended in a draw!" << endl;
			cout << "Current Scores: " << endl;
			cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		}
	}
	
	else if (score1 == 1 && score2 == 0) {
		cout << name1 << " is the winner!" << endl;
		cout << "Current Scores:" << endl;
		cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		cout << "Starting a new game..." << endl;
		print(matrix);
		gamePlayer(name2, symbol2, name1, symbol1, score2, score1);
		if (score1 == 2 && score2 == 0) {
			cout << name1 << " is the winner!" << endl;
			cout << "Current Scores: " << endl;
			cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		}
		else if (score1 == 1 && score2 == 1) {
			cout << name2 << " is the winner!" << endl;
			cout << "Current Scores: " << endl;
			cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		}
		else if (score1 == 1 && score2 == 0) {
			cout << "The game ended in a draw!" << endl;
			cout << "Current Scores: " << endl;
			cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		}
	}

	else if (score1 == 0 && score2 == 1) {
		cout << name2 << " is the winner!" << endl;
		cout << "Current Scores:" << endl;
		cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		cout << "Starting a new game..." << endl;
		print(matrix);
		gamePlayer(name2, symbol2, name1, symbol1, score2, score1);
		if (score1 == 1 && score2 == 1) {
			cout << name1 << " is the winner!" << endl;
			cout << "Current Scores: " << endl;
			cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		}
		else if (score1 == 0 && score2 == 2) {
			cout << name2 << " is the winner!" << endl;
			cout << "Current Scores: " << endl;
			cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		}
		else if (score1 == 0 && score2 == 1) {
			cout << "The game ended in a draw!" << endl;
			cout << "Current Scores: " << endl;
			cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl << endl;
		}
	}

	cout << "Final Scores: " << endl;
	cout << name1 << ": " << score1 << "   " << name2 << ": " << score2 << endl;
	
	if (score1 == score2) {
		cout << "The overall game ended in a draw!" << endl;
	}
	else if (score1 > score2) {
		cout << name1 << " is the overall winner!" << endl;
	}
	else if (score1 < score2) {
		cout << name2 << " is the overall winner!" << endl;
	}

	return 0;
}