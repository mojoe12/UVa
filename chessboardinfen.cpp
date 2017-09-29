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
	
	char k = (ifwhite) ? 'k' : 'K';
	if (board[ky-1][kx-1] == k || board[ky-1][kx] == k ||
		board[ky-1][kx+1] == k || board[ky][kx-1] == k ||
		board[ky][kx+1] == k || board[ky+1][kx-1] == k ||
		board[ky+1][kx] == k || board[ky+1][kx+1] == k) return true;
	
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
	string s;
	while (cin >> s) {
		
		vector<string> board (12);
		board[0] = board[1] = board[10] = board[11] = "............";
		
		int index = 0;
		for (int i = 2; i < 10; i++) {
			board[i] = "............";
			int minindex = 2;
			while (index < s.size() && s[index] != '/') {
				if (s[index] > '0' && s[index] < '9') {
					minindex += s[index] - '0';
				}
				else board[i][minindex++] = s[index];
				index++;
			}
			index++;
		}
		
		//for (int i = 0; i < 12; i++) cout << board[i] << endl;
		
		int count = 0;
		for (int i = 2; i < 10; i++) {
			for (int j = 2; j < 10; j++) {
				if (board[i][j] == '.' && !check(board, j, i, true) && !check(board, j, i, false)) count++;
			}
		}
		
		cout << count << endl;
		
	}
}