#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;



int main() {

	vector<int> throws;
	int x;
	while (cin >> x) {
		if (!x) break;
		throws.push_back(x);
	}
	
	while (true) {
		int np;
		cin >> np;
		if (!np) break;
		
		int a, b;
		vector<int> chutes (100, 0);
		while (cin >> a >> b) {
			if (!a && !b) break;
			chutes[a] = b;
		}
				
		vector<int> special (100, 0);
		int y;
		while (cin >> y) {
			if (!y) break;
			if (y > 0) special[y] = 2;
			else special[-y] = 1;
		}
		
		vector<int> places (np, 0);
		vector<bool> lost (np, false);
		int winner = 0, numextra = 0;
		for (int turn = 0; !winner && turn < throws.size(); turn++) {
			int player = (turn - numextra) % np;
			if (lost[player]) {
				numextra--; // ?
				lost[player] = false;
				continue;
			}
			if (places[player] + throws[turn] > 100) continue;
			places[player] += throws[turn];
			//cout << player << ' ' << places[player] << endl;
			if (places[player] == 100) winner = player+1;
			else if (chutes[places[player]]) places[player] = chutes[places[player]];
			else if (special[places[player]] == 1) lost[player] = true;
			else if (special[places[player]] == 2) numextra++;
		}
		
		cout << winner << endl;
	}


}


