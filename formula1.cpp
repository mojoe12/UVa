#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	while (true) {
		int nraces, npilots;
		cin >> nraces >> npilots;
		if (nraces == 0 && npilots == 0) break;
		vector< vector<int> > results (nraces, vector<int> (npilots));
		for (int i = 0; i < nraces; i++) {
			for (int j = 0; j < npilots; j++) {
				int x;
				cin >> x;
				results[i][x-1] = j;
			}
		}
		int nsystems;
		cin >> nsystems;
		
		for (int i = 0; i < nsystems; i++) {
			int nprizes;
			cin >> nprizes;
			vector<int> prizes (nprizes);
			for (int j = 0; j < nprizes; j++) cin >> prizes[j];
			vector<int> scores (npilots);
			for (int j = 0; j < nraces; j++) {
				for (int k = 0; k < nprizes; k++) {
					scores[results[j][k]] += prizes[k];
				} 
			}
			int max = *max_element(scores.begin(), scores.end());
			bool ifspace = false;
			for (int j = 0; j < npilots; j++) {
				if (scores[j] == max) {
					if (ifspace) cout << " ";
					else ifspace = true;
					cout << j+1;
				}
			}
			cout << endl;
		}
	}
}