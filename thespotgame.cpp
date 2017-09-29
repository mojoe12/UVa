#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations

bool ifequal (vector< vector<bool> > a, vector< vector<bool> > b) {
	
	bool no = true, one = true, two = true, three = true;
	int n = a.size(); // assuming square
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			no = no && a[i][j] == b[i][j];
			one = one && a[i][j] == b[n-i-1][j];
			two = two && a[i][j] == b[i][n-j-1];
			three = three && a[i][j] == b[n-i-1][n-j-1];
		}
	}
	return no || one || two || three;
}

int main() {
	
	// setup input
	int n;
	while (cin >> n) {
		if (!n) break;
		
		int winner = 0, wonmove = 0;
		
		vector< vector<bool> > cboard (n, vector<bool> (n, false));
		vector< vector< vector<bool> > > pboards;
		
		for (int i = 0; i < 2*n; i++) {
			int x, y;
			char move;
			cin >> x >> y >> move;
			cboard[x-1][y-1] = (move == '+');
			
			bool over = false;
			for (int j = 0; !over && j < pboards.size(); j++) {
				over = ifequal(cboard, pboards[j]);
			}
			
			if (over) {
				winner = 2 - (i % 2);
				wonmove = i + 1;
			}
			
			pboards.push_back(cboard);
			
		}
		
		if (winner) cout << "Player " << winner << " wins on move " << wonmove << endl;
		else cout << "Draw\n";
		
	}
}