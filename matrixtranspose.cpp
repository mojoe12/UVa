#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int main() {
	
	// setup input
	int n, m;
	while (cin >> n >> m) {
		
		vector< vector< pair<int, int> > > transposed (m);
		
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			vector<int> indices (num);
			for (int j = 0; j < num; j++) cin >> indices[j];
			for (int j = 0; j < num; j++) {
				int input;
				cin >> input;
				transposed[indices[j]-1].push_back( make_pair(i+1, input) );
			}
		}
		
		cout << m << ' ' << n << endl;
		for (int i = 0; i < m; i++) {
			int num = transposed[i].size();
			cout << num;
			for (int j = 0; j < num; j++) {
				cout << ' ' << transposed[i][j].first;
			}
			cout << endl;
			for (int j = 0; j < num-1; j++) {
				cout << transposed[i][j].second << ' ';
			}
			if (num) cout << transposed[i][num-1].second;
			cout << endl;
		}
	}

}