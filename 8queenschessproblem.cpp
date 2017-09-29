#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool ifSafe (vector<vector<bool> >& board, int row, int col);
void findSafeColumn (int col, vector<int>& board, int& nsol);

int main(int argc, char *argv[]) {
	int k;
	cin >> k;

	for (int c = 0; c < k; c++) {

		int x, y;
		cin >> x >> y;
		x--;
		y--;
		
		if (c) cout << endl;
		cout << "SOLN       COLUMN\n";
		cout << " #      1 2 3 4 5 6 7 8\n\n";
		
		vector<int> board (8, -1);
		board[y] = x;
		// index is column, result is row I THINK??
		int nsol = 0;
		findSafeColumn(0, board, nsol);
		
		// output
	}
}

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

void findSafeColumn (int col, vector<int>& board, int& nsol) {
	if (col == 8) {
		nsol++;
		if (nsol < 10) cout << ' ';
		cout << nsol << "     ";
		for (int i = 0; i < 8; i++) {
			cout << ' ' << (board[i]+1);
		}
		cout << endl;
		return;
	}
	
	if (board[col] != -1) {
		findSafeColumn(col+1, board, nsol);
		return;
	}
	
	for (int row = 0; row < 8; row++) {
		if (ifSafe(board, row, col)) {
			board[col] = row;
			findSafeColumn(col+1, board, nsol);
			board[col] = -1;
		}
	}
}