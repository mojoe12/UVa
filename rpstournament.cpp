#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int play (char a, char b) {
	if (a == 'r' && b == 's') return 1;
	if (a == 's' && b == 'r') return 2;
	if (a == 's' && b == 'p') return 1;
	if (a == 'p' && b == 's') return 2;
	if (a == 'p' && b == 'r') return 1;
	if (a == 'r' && b == 'p') return 2;
	return 0;
}

int main() {
	
	// setup input
	int n, k;
	for (int c = 0; cin >> n; c++) {
		if (!n) break;
		cin >> k;
		
		int ngames = k * n * (n-1) / 2;
		
		vector<int> wins (n, 0);
		vector<int> losses (n, 0);
		
		for (int i = 0; i < ngames; i++) {
			int p1, p2;
			string c1, c2;
			cin >> p1 >> c1 >> p2 >> c2;
			
			int winner = play(c1[0], c2[0]);
			if (winner == 1) {
				wins[p1-1]++;
				losses[p2-1]++;
			}
			else if (winner == 2) {
				wins[p2-1]++;
				losses[p1-1]++;
			}
		}
		
		if (c) cout << endl;
		for (int i = 0; i < n; i++) {
			if (wins[i] + losses[i] > 0) {
				double wp = wins[i] * 1.0 / (wins[i] + losses[i]);
				cout << fixed << setprecision(3);
				cout << wp << endl;
			}
			else cout << "-\n";
		}
		
	}


	// loop through it, apply function


	// output answer


}

// function definitions

