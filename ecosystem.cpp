#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int main() {
	
	int n;
	while (cin >> n) {
		vector< vector<bool> > ifeats (n, vector<bool> (n, false)); // i eats j
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				cin >> x;
				if (x == 1) ifeats[i][j] = true;
			}
		}
		
		vector<int> ci, cj, ck;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < j; k++) {
					if (ifeats[i][j] && ifeats[j][k] && ifeats[k][i]) {
						ci.push_back(i);
						cj.push_back(j);
						ck.push_back(k);
					}
				}
			}
			
			for (int j = i+1; j < n; j++) {
				for (int k = j+1; k < n; k++) {
					if (ifeats[i][j] && ifeats[j][k] && ifeats[k][i]) {
						ci.push_back(i);
						cj.push_back(j);
						ck.push_back(k);
					}
				}
			}
		}
		
		for (int i = 0; i < ci.size(); i++) {
			cout << ci[i]+1 << ' ' << cj[i]+1;
			cout << ' ' << ck[i]+1 << endl;
		}
		cout << "total:" << ci.size() << endl << endl;
		
	}




}


