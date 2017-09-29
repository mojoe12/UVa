#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int k;
	cin >> k;
	for (int c = 0; c < k; c++) {
		int n;
		cin >> n;
		vector< vector<int> > arri (n, vector<int> (n));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arri[i][j];
			}
		}
		
		vector< vector<int> > arr (2*n, vector<int> (2*n));

		
		for (int i = 0; i < 2*n; i++) {
			for (int j = 0; j < 2*n; j++) {
				int& val = arr[i][j];
				val = arri[i % n][j % n];
				if (i) val += arr[i-1][j];
				if (j) val += arr[i][j-1];
				if (i && j) val -= arr[i-1][j-1];
			}
		}
		
		int bestsum = arr[0][0];
		for (int si = 0; si < n; si++) {
			for (int sj = 0; sj < n; sj++) {
				for (int ei = si; ei < si + n; ei++) {
					for (int ej = sj; ej < sj + n; ej++) {
						int subsum = arr[ei][ej];
						if (si) subsum -= arr[si - 1][ej];
						if (sj) subsum -= arr[ei][sj - 1];
						if (si && sj) subsum += arr[si - 1][sj - 1];
						bestsum = max(bestsum, subsum);
					}
				}

			}
		}
		
		cout << bestsum << endl;
		
		
	}




}


