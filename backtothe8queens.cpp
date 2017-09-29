#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ifSafe (vector<int>& board, int row, int col);
void findSafeColumn (vector< vector<int> >& boards, int col, vector<int>& cboard);

int main() {
	
	vector< vector<int> > boards;
	boards.reserve(92);
	vector<int> nboard(8, -1);
	findSafeColumn(boards, 0, nboard);
	
	int x, counter = 0;
	while (cin >> x) {
		counter++;
		vector<int> board (8);
		board[0] = x;
		for (int i = 1; i < 8; i++) cin >> board[i];
		
		int minmoves = 8;
		for (int i = 0; i < 92; i++) {
			int nmoves = 0;
			for (int j = 0; j < 8; j++) {
				if (boards[i][j] != board[j] - 1) nmoves++;
			}
			minmoves = min(minmoves, nmoves);
		}
		cout << "Case " << counter << ": ";
		cout << minmoves << endl;
		
	}
}

// function definitions

bool ifSafe (vector<int>& board, int row, int col) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == row && j == col) continue;
			if (i == row && board[j] == i) return false;
			if (j == col && board[j] == i) return false;
			if (abs(row-i) == abs(col-j) && board[j] == i) return false;
		}
	}
	return true;
}

void findSafeColumn (vector< vector<int> >& boards, int col, vector<int>& cboard) {
	
	if (col == 8) {
		boards.push_back(cboard);
		return;
	}
	
	for (int row = 0; row < 8; row++) {
		if (ifSafe(cboard, row, col)) {
			cboard[col] = row;
			findSafeColumn(boards, col+1, cboard);
			cboard[col] = -1;
		}
	}
}