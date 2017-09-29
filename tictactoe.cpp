#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations

bool ifsolved (vector<string> board, char c) {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == c) return true;
	}
	for (int i = 0; i < 3; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == c) return true;
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == c) return true;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == c) return true;
	return false;
}


int main() {
	
	// setup input
	int k;
	cin >> k;
	
	vector<bool> ans (k);
	for (int c = 0; c < k; c++) {
		vector<string> board (3);
		for (int i = 0; i < 3; i++) cin >> board[i];
		
		int numx = 0, numo = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == 'X') numx++;
				else if (board[i][j] == 'O') numo++;
			}
		}
		
		bool ifok = true;
		
		if (numx - 1 > numo || numx < numo) ifok = false;
		
		if (ifsolved(board, 'O') && ifsolved(board, 'X')) ifok = false;
		
		if (ifsolved(board, 'O')) {
			if (numo != numx) ifok = false;
			int count = 0;
			for (int i = 0; i < 3; i++) {
				if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'O') count++;
			}
			if (count > 1) ifok = false;
			count = 0;
			for (int i = 0; i < 3; i++) {
				if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 'O') count++;
			}
			if (count > 1) ifok = false;
		}
		
		if (ifsolved(board, 'X')) {
			if (numo + 1 != numx) ifok = false;
			int count = 0;
			for (int i = 0; i < 3; i++) {
				if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'X') count++;
			}
			if (count > 1) ifok = false;
			count = 0;
			for (int i = 0; i < 3; i++) {
				if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 'X') count++;
			}
			if (count > 1) ifok = false;
		}
		
		// if o wins, then numx == numo and x does not win and o does not win twice
		// if x wins, then numx == numo + 1 and o does not win and x does not win twice
		
		ans[c] = ifok;
		
	}
	
	for (int i = 0; i < k; i++) {
		if (ans[i]) cout << "yes\n";
		else cout << "no\n";
	}


	// loop through it, apply function


	// output answer


}

// function definitions

