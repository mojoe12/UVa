#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

// function declarations
char killer (char c) {
	if (c == 'R') return 'P';
	if (c == 'P') return 'S';
	return 'R';
}

int main() {
	
	// setup input
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n, m, d;
		cin >> n >> m >> d;
		
		vector<string> game (n);
		for (int i = 0; i < n; i++) cin >> game[i];
		
		for (int i = 0; i < d; i++) {
			vector<string> next = game;
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					char k = killer(game[i][j]);
					if ( 
						(i && game[i-1][j] == k) ||
						(j && game[i][j-1] == k) ||
						(i < n-1 && game[i+1][j] == k) ||
						(j < m-1 && game[i][j+1] == k)
					) next[i][j] = k;
				}
			}
			
			game = next;
		}
		
		if (c) cout << endl;
		for (int i = 0; i < n; i++) {
			cout << game[i] << endl;
		}
		
	}

}