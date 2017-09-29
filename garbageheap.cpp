#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;



int main() {
	
	int nc;
	cin >> nc;
	for (int c = 0; c < nc; c++) {
		if (c) cout << endl;
		
		int n, m, p;
		cin >> n >> m >> p;
		
		vector< vector< vector<long long> > > arr (n, vector< vector<long long> > (m, vector<long long> (p)));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < p; k++) {
					long long& x = arr[i][j][k];
					cin >> x;
					if (j) x += arr[i][j-1][k];
					if (k) x += arr[i][j][k-1];
					if (j && k) x -= arr[i][j-1][k-1];
					//cout << x << endl;
				}
			}
		}
		
		long long bestval = arr[0][0][0];
		for (int sj = 0; sj < m; sj++) {
			for (int sk = 0; sk < p; sk++) {
				for (int ej = sj; ej < m; ej++) {
					for (int ek = sk; ek < p; ek++) {
						long long currval = 0;
						for (int i = 0; i < n; i++) {
							
							long long subsum = 0;
							subsum += arr[i][ej][ek];
							if (sj) subsum -= arr[i][sj-1][ek];
							if (sk) subsum -= arr[i][ej][sk-1];
							if (sj && sk) subsum += arr[i][sj-1][sk-1];
							
							if (currval + subsum < 0) currval = 0;
							else currval += subsum;
							
							if (currval) bestval = max(bestval, currval);
						}
					}
				}
			}
		}
		
		cout << bestval << endl;
	}



}


