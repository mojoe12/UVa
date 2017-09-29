#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n, m;
		cin >> n >> m;
		if (!n && !m) break;
		
		vector< vector<int> > arr (n, vector<int> (n, 1));
		
		for (int x = 0; x < m; x++) {
			int si, sj, ei, ej;
			cin >> si >> sj >> ei >> ej;
			for (int i = si-1; i < ei; i++) {
				for (int j = sj-1; j < ej; j++) {
					arr[i][j] = -10000;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i) arr[i][j] += arr[i-1][j];
				if (j) arr[i][j] += arr[i][j-1];
				if (i && j) arr[i][j] -= arr[i-1][j-1];
			}
		}
		
		int bestsum = 0;
		for (int si = 0; si < n; si++) {
			for (int sj = 0; sj < n; sj++) {
				for (int ei = si; ei < n; ei++) {
					for (int ej = sj; ej < n; ej++) {
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


