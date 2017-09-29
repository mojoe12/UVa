#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int m, n;
	while (cin >> m >> n) {
		if (!m && !n) break;
		
		vector< vector<int> > heights (m, vector<int> (n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> heights[i][j];
			}
		}
		
		vector< vector<int> > diagonals (m + n - 1);
		for (int starti = m-1; starti >= 0; starti--) {
			for (int i = starti, j = 0; i < m && j < n; i++, j++) {
				diagonals[starti].push_back(heights[i][j]);
			}
		}
		for (int startj = 1; startj < n; startj++) {
			for (int i = 0, j = startj; i < m && j < n; i++, j++) {
				diagonals[m + startj - 1].push_back(heights[i][j]);
			}
		}
		
		int q;
		cin >> q;
		for (int x = 0; x < q; x++) {
			int a, b;
			cin >> a >> b;
			int maxdist = 0;
			for (int i = 0; i < diagonals.size(); i++) {
				int dist = upper_bound(diagonals[i].begin(), diagonals[i].end(), b) - upper_bound(diagonals[i].begin(), diagonals[i].end(), a-1);
				maxdist = max(maxdist, dist);
			}
			cout << maxdist << endl;
		}
		cout << "-\n";
	}




}


