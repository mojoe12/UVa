#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int nplayers, nladders, nrolls;
		cin >> nplayers >> nladders >> nrolls;
		vector<int> start (nladders);
		vector<int> end (nladders);
		for (int i = 0; i < nladders; i++) cin >> start[i] >> end[i];
		vector<int> pos (nplayers);
		fill(pos.begin(), pos.end(), 1);
		bool finished = false;
		for (int i = 0; i < nrolls; i++) {
			int move;
			cin >> move;
			if (finished) continue;
			int p = i % nplayers;
			pos[p] += move;
			for (int j = 0; j < nladders; j++) {
				if (pos[p] == start[j]) {
					pos[p] = end[j];
					break;
				}
			}			
			if (pos[p] >= 100) {
				pos[p] = 100;
				finished = true;
			}
		}
		for (int i = 0; i < nplayers; i++) {
			cout << "Position of player " << i+1 << " is " << pos[i] << ".\n";
		}
	}
}