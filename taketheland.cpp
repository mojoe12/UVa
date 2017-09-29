#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int 
	while (true) {
		int n, m;
		cin >> n >> m;
		if (!n && !m) break;
		
		vector< vector<int> > arr (n, vector<int> (m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int& val = arr[i][j];
				cin >> val;
				val = (val) ? -10000 : 1;
				if (i) val += arr[i-1][j];
				if (j) val += arr[i][j-1];
				if (i && j) val -= arr[i-1][j-1];
			}
		}
		
		int bestsum = 0;
		for (int si = 0; si < n; si++) {
			for (int sj = 0; sj < m; sj++) {
				for (int ei = si; ei < n; ei++) {
					for (int ej = sj; ej < m; ej++) {
						int subsum = arr[ei][ej];
						if (si) subsum -= arr[si-1][ej];
						if (sj) subsum -= arr[ei][sj-1];
						if (si && sj) subsum += arr[si-1][sj-1];
						bestsum = max(bestsum, subsum);
					}
				}
			}
		}
		
		cout << bestsum << endl;
	}
	




}


