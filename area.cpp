#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int k;
	cin >> k;
	for (int c = 1; c <= k; c++) {
		int n, m, b;
		cin >> n >> m >> b;
		
		vector< vector<int> > arr (n, vector<int> (m));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int& val = arr[i][j];
				cin >> val;
				if (i) val += arr[i-1][j];
				if (j) val += arr[i][j-1];
				if (i && j) val -= arr[i-1][j-1];
			}
		}
		
		int maxarea = 0, mincost = 0;
		for (int si = 0; si < n; si++) {
			for (int sj = 0; sj < m; sj++) {
				for (int ei = si; ei < n; ei++) {
					for (int ej = sj; ej < m; ej++) {
						int area = (1 + ej - sj) * (1 + ei - si);
						int subsum = arr[ei][ej];
						if (si) subsum -= arr[si-1][ej];
						if (sj) subsum -= arr[ei][sj-1];
						if (si && sj) subsum += arr[si-1][sj-1];
						
						if (subsum <= b && area > maxarea) {
							maxarea = area;
							mincost = subsum;
						}
						if (area == maxarea) mincost = min(mincost, subsum);
					}
				}
			}
		}
		
		cout << "Case #" << c << ": " << maxarea << ' ' << mincost << endl;
	}




}


