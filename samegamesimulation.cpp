#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

void dropdown(vector< vector<int> >& game) {
	for (int j = game[0].size(); j > 0; j--) {
		for (int i = 1; i < game.size(); i++) {
			if (game[i][j] == -1) {
				game[i][j] = game[i-1][j];
				game[i-1][j] = -1;
			}
		}
	}
}




bool play (vector< vector<int> >& game, vector< vector<int> >& newgame, int i, int j, int x, vector<bool>& badcolumns) {
	cout << i << ' ' << j << ' ' << x << endl;
	
	if (i < 0 || i >= game.size() || j < 0 || j >= game[0].size()) return false;
	if (badcolumns[j]) return play(game, newgame, i, j-1, x, badcolumns);
	if (x > -1 && game[i][j] != x) return false;
	bool ok = (x != -1);
	x = game[i][j];
	
	// i have to make a new game
	
	ok = ok || play(game, newgame, i-1, j, x, badcolumns);
	ok = ok || play(game, newgame, i+1, j, x, badcolumns);
	ok = ok || play(game, newgame, i, j-1, x, badcolumns);
	ok = ok || play(game, newgame, i, j+1, x, badcolumns);
	if (ok) newgame[i][j] = -1;
	return ok;
}


int main() {
	int m, n;
	for (int c = 1; cin >> m >> n; c++) {
		if (!m || !n) break;
		
		vector< vector<int> > game (m, vector<int> (n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> game[i][j];
			}
		}


		vector<bool> badcolumns (n, false);
		int x, y;
		while (cin >> x >> y) {
			if (!x && !y) break;
			if (count(badcolumns.begin(), badcolumns.end(), true) == badcolumns.size()) continue;
			vector< vector<int> > newgame = game;
			play(game, newgame, x-1, y-1, -1, badcolumns);
			for (int j = 0; j < n; j++) {
				bool bad = true;
				for (int i = 0; i < m; i++) bad = bad && game[i][j] == -1;
				if (bad) badcolumns[j] = true;
			}
			
			dropdown(newgame);
			game = newgame;
			
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) cout << game[i][j] << ' '; cout << endl;
			}
			
		}
		
		cout << "Grid " << c << ".\n";
		if (count(badcolumns.begin(), badcolumns.end(), true) == badcolumns.size()) cout << "    Game Won\n";
		else {
			for (int i = 0; i < m; i++) {
				cout << "   ";
				for (int j = 0; j < n; j++) {
					if (game[i][j] == -1) cout << "  ";
					else cout << ' ' << game[i][j];
				}
				cout << endl;
			}
		}
		
	}
	




}


