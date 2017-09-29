#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

void input (vector<int>& p, vector< vector<bool> >& m, int im, int jm) {
	for (int i = 0; i < im; i++) {
		cin >> p[i];
		for (int j = 0; j < jm; j++) {
			int x;
			cin >> x;
			m[i][j] = (x == 0);
		}
	}
}

int main() {
	
	int t, r, h;
	while (cin >> t >> r >> h) {
				
		vector<int> tprices (t), rprices (r), hprices (h);
		vector< vector<bool> > tmatches (t, vector<bool> (r));
		input(tprices, tmatches, t, r);
		vector< vector<bool> > rmatches (r, vector<bool> (h));
		input(rprices, rmatches, r, h);
		vector< vector<bool> > hmatches (h, vector<bool> (t));
		input(hprices, hmatches, h, t);
		
		
		int minprice = -1;
		int tnum = -1, rnum = -1, hnum = -1;
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < h; k++) {
					if (tmatches[i][j] && rmatches[j][k] && hmatches[k][i]) {
						int price = tprices[i] + rprices[j] + hprices[k];
						if (minprice == -1 || price < minprice) {
							tnum = i;
							rnum = j;
							hnum = k;
							minprice = price;
						}
					}
				}
			}
		}
		
		if (minprice == -1) cout << "Don't get married!\n";
		else cout << tnum << ' ' << rnum << ' ' << hnum << ':' << minprice << endl;
	}
}