#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int n, m;
	for (int c = 0; cin >> n >> m; c++) {
		if (c) cout << endl;
		vector< vector<int> > arr (n, vector<int> (n));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int& val = arr[i][j];
				cin >> val;
				if (i) val += arr[i-1][j];
				if (j) val += arr[i][j-1];
				if (i && j) val -= arr[i-1][j-1];
			}
		}
		
		m--;
		long long totalsum = 0;
		for (int si = 0; si < n - m; si++) {
			for (int sj = 0; sj < n - m; sj++) {
				int ei = si + m, ej = sj + m;
				int subsum = arr[ei][ej];
				if (si) subsum -= arr[si - 1][ej];
				if (sj) subsum -= arr[ei][sj - 1];
				if (si && sj) subsum += arr[si - 1][sj - 1];
				cout << subsum << endl;
				totalsum += subsum;
			}
		}
		
		cout << totalsum << endl;
		
		
	}




}


