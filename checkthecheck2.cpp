#include <iostream>
#include <vector>

using namespace std;

void pawn (int i, int j, vector< vector<char> >& board, vector< vector<bool> >& boardb) {
	int newi = i-1;
	if (board[i][j] == 'p') newi = i+1;
	if boardb[newi][j+1]
}
void rook (int i, int j, vector< vector<char> >& board, vector< vector<bool> >& boardb) {
	
}
void bish (int i, int j, vector< vector<char> >& board, vector< vector<bool> >& boardb) {
	
}
void quen (int i, int j, vector< vector<char> >& board, vector< vector<bool> >& boardb) {
	
}
void king (int i, int j, vector< vector<char> >& board, vector< vector<bool> >& boardb) {
	
}
void knig (int i, int j, vector< vector<char> >& board, vector< vector<bool> >& boardb) {
	
}

int main(int argc, char *argv[]) {
	for (int cc = 0; ; cc++) {
		
		vector< vector<bool> > boardb (8, vector<bool> (8)); // attacked by black
		vector< vector<bool> > boardw (8, vector<bool> (8)); // attacked by white
		
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				boardb[i][j] = true;
				boardw[i][j] = true;
			}
		}
		
		vector< vector<char> > board;
		int ki = -1, kj = -1, Ki = -1, Kj = -1;
		
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> board[i][j];
				if (board[i][j] == 'k') {
					ki = i;
					kj = j;
				}
				else if (board[i][j] == 'K') {
					Ki = i;
					Kj = j;
				}
				else if (board[i][j] < '.') j--;
			}
		}
		
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char c = board[i][j];
				     if (c == 'p' || c == 'P') pawn(i, j, board, (c > 'Z') ? boardw : boardb);
				else if (c == 'r' || c == 'R') rook(i, j, board, (c > 'Z') ? boardw : boardb);
				else if (c == 'b' || c == 'B') bish(i, j, board, (c > 'Z') ? boardw : boardb);
				else if (c == 'q' || c == 'Q') quen(i, j, board, (c > 'Z') ? boardw : boardb);
				else if (c == 'k' || c == 'K') king(i, j, board, (c > 'Z') ? boardw : boardb);
				else if (c == 'n' || c == 'N') knig(i, j, board, (c > 'Z') ? boardw : boardb);
			}
		}
	}
}