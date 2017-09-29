#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>


using namespace std;



int main() {
	
	int nc;
	cin >> nc;
	for (int c = 1; c <= nc; c++) {
		if (c > 1) cout << endl;
		int nballs, ntix;
		cin >> nballs >> ntix;
		vector<int> balls (nballs);
		for (int i = 0; i < nballs; i++) cin >> balls[i];
		
		vector<int> combwins (4);
		for (int i = 0; i < 4; i++) cin >> combwins[i];
		
		vector<int> winnings (ntix, 0);
		for (int t = 0; t < ntix; t++) {
			map<int, pair<int, int> > ticketnums;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					int x;
					cin >> x;
					ticketnums.insert(make_pair(x, make_pair(i, j)));
				}
			}
			
			vector< vector<bool> > ticket (5, vector<bool> (5, false));
			
			vector<bool> ifcomb (3, false);
			
			for (int b = 0; b < nballs; b++) {
				if (!ticketnums.count(balls[b])) continue;
				
				ticket[ticketnums[balls[b]].first][ticketnums[balls[b]].second] = true;
				
				vector<bool> nowtrue (4, false);
				nowtrue[0] = ticket[0][0] && ticket[0][4] && ticket[4][0] && ticket[4][4];
				nowtrue[1] = ticket[2][0] && ticket[2][1] && ticket[2][2] && ticket[2][3] && ticket[2][4];
				nowtrue[2] = nowtrue[0] && ticket[1][1] && ticket[1][3] && ticket[3][1] && ticket[3][3] && ticket[2][2];
				nowtrue[3] = true;
				for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (!ticket[i][j]) nowtrue[3] = false;
				
				for (int i = 0; i < 4; i++) {
					if (!ifcomb[i] && nowtrue[i] && (b < 35 + 5 * i || i == 3)) { // <=
						winnings[t] += combwins[i];
						ifcomb[i] = true;
					}
				}
			}
		}
		
		cout << "Case " << c << ":\n";
		for (int t = 0; t < ntix; t++) {
			cout << winnings[t] << endl;
		}
	}

}