#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations

bool check (vector<string> board, int kx, int ky, bool ifwhite) 
{
	char p = (ifwhite) ? 'p' : 'P';
	if (ifwhite && (board[ky-1][kx-1] == p || board[ky-1][kx+1] == p)) return true;
	if (!ifwhite && (board[ky+1][kx-1] == p || board[ky+1][kx+1] == p)) return true;
	
	char n = (ifwhite) ? 'n' : 'N';
	if (board[ky-2][kx+1] == n || board[ky-2][kx-1] == n || 
		board[ky+2][kx+1] == n || board[ky+2][kx-1] == n || 
		board[ky-1][kx+2] == n || board[ky-1][kx-2] == n || 
		board[ky+1][kx+2] == n || board[ky+1][kx-2] == n) return true;
	
	char q = (ifwhite) ? 'q' : 'Q';
	char r = (ifwhite) ? 'r' : 'R';
	for (int i = ky+1, j = kx; i < 10; i++) {
		if (board[i][j] != '.') {
			if (board[i][j] == q || board[i][j] == r) return true;
			else break;
		}
	}
	for (int i = ky-1, j = kx; i > 1; i--) {
		if (board[i][j] != '.') {
			if (board[i][j] == q || board[i][j] == r) return true;
			else break;
		}
	}
	for (int i = ky, j = kx+1; j < 10; j++) {
		if (board[i][j] != '.') {
			if (board[i][j] == q || board[i][j] == r) return true;
			else break;
		}
	}
	for (int i = ky, j = kx-1; j > 1; j--) {
		if (board[i][j] != '.') {
			if (board[i][j] == q || board[i][j] == r) return true;
			else break;
		}
	}
	
	char b = (ifwhite) ? 'b' : 'B';
	for (int i = ky+1, j = kx+1; i < 10 && j < 10; i++, j++) {
		if (board[i][j] != '.') {
			if (board[i][j] == q || board[i][j] == b) return true;
			else break;
		}
	}
	
	for (int i = ky+1, j = kx-1; i < 10 && j > 1; i++, j--) {
		if (board[i][j] != '.') {
			if (board[i][j] == q || board[i][j] == b) return true;
			else break;
		}
	}
	for (int i = ky-1, j = kx+1; i > 1 && j < 10; i--, j++) {
		if (board[i][j] != '.') {
			if (board[i][j] == q || board[i][j] == b) return true;
			else break;
		}
	}
	for (int i = ky-1, j = kx-1; i > 1 && j > 1; i--, j--) {
		if (board[i][j] != '.') {
			if (board[i][j] == q || board[i][j] == b) return true;
			else break;
		}
	}
	
	return false;
}



int main() {
	
	// setup input
	
	for (int c = 1; ; c++) {
		vector<string> board (12);
		board[0] = board[1] = board[10] = board[11] = "............";
		for (int i = 2; i < 10; i++) {
			string s;
			cin >> s;
			s = ".." + s + "..";
			board[i] = s;
		}
		
		int wkx = -1, wky = -1, bkx = -1, bky = -1;
		for (int i = 2; i < 10; i++) {
			for (int j = 2; j < 10; j++) {
				if (board[i][j] == 'K') {
					wkx = j;
					wky = i;
				}
				else if (board[i][j] == 'k') {
					bkx = j;
					bky = i;
				}
			}
		}
		
		if (wkx < 0) break;
		
		cout << "Game #" << c << ": ";
		if (check(board, wkx, wky, true)) cout << "white";
		else if (check(board, bkx, bky, false)) cout << "black";
		else cout << "no";
		cout << " king is in check.\n";
	}
}