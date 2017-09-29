#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool ifSafe (vector<vector<bool> >& board, int row, int col);
void findSafeColumn (int row, vector<int>& board, vector<vector<int> >& scores, int& currscore, int& bestscore);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		vector<vector<int> > scores (8, vector<int> (8));
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> scores[i][j];
			}
		}
		int bestscore = 0, initscore = 0;
		vector<int> board (8, -1);
		findSafeColumn(0, board, scores, initscore, bestscore);
		cout.width(5);
		cout << right << bestscore << endl;
	}
}

bool ifSafe (vector<int>& board, int row, int col) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == row && j == col) continue;
			if (i == row && board[i] == j) return false;
			if (j == col && board[i] == j) return false;
			if (abs(row-i) == abs(col-j) && board[i] == j) return false;
		}
	}
	return true;
}

void findSafeColumn (int row, vector<int>& board, vector<vector<int> >& scores, int& currscore, int& bestscore) {
	if (row == 8) {
		bestscore = max(bestscore, currscore);
		return;
	}
	
	for (int col = 0; col < 8; col++) {
		if (ifSafe(board, row, col)) {
			board[row] = col;
			currscore += scores[row][col];
			findSafeColumn(row+1, board, scores, currscore, bestscore);
			board[row] = -1;
			currscore -= scores[row][col];
		}
	}
}