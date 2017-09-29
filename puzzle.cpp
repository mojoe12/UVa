#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	// setup input
	string s;
	for (int c = 1; getline(cin, s); c++) {
		if (s[0] == 'Z' && s.length() != 5) break;
		vector<string> board (5);
		board[0] = s;
		for (int i = 1; i < 5; i++) getline(cin, board[i]);
		
		int bi = -1, bj = -1;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (board[i][j] == ' ') {
					bi = i;
					bj = j;
				}
			}
		}
				
		bool legal = true;
		char move;
		cin >> move;
		while (move != '0') {
			if (legal) {
				if (move == 'A') {
					if (bi == 0) legal = false;
					else {
						swap(board[bi][bj], board[bi-1][bj]);
						bi--;
					}
				}
				else if (move == 'B') {
					if (bi == 4) legal = false;
					else {
						swap(board[bi][bj], board[bi+1][bj]);
						bi++;
					}
				}
				else if (move == 'R') {
					if (bj == 4) legal = false;
					else {
						swap(board[bi][bj], board[bi][bj+1]);
						bj++;
					}
				}
				else if (move == 'L') {
					if (bj == 0) legal = false;
					else {
						swap(board[bi][bj], board[bi][bj-1]);
						bj--;
					}
				}
				else legal = false;
			}
			cin >> move;
		}
		cin.ignore();
		
		if (c > 1) cout << endl;
		cout << "Puzzle #" << c << ":\n";
		if (legal) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 4; j++) cout << board[i][j] << ' ';
				cout << board[i][4] << endl;
			}		
		}
		else cout << "This puzzle has no final configuration.\n";
	}
}