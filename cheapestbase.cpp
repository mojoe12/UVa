#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int cost (int n, int b, vector<int>& costs) {
	int sumcost = 0;
	while (n) {
		sumcost += costs[n % b];
		n /= b;
	}
	return sumcost;
}

int main() {
	
	int k;
	cin >> k;
	
	for (int c = 0; c < k; c++) {
		vector<int> costs (36);
		for (int i = 0; i < 36; i++) cin >> costs[i];
		if (c) cout << endl;
		cout << "Case " << c+1 << ":\n";
		
		int t;
		cin >> t;
		for (int i = 0; i < t; i++) {
			int n;
			cin >> n;
			vector<int> bestbase;
			int mincost = cost(n, 2, costs);
			for (int b = 2; b < 37; b++) {
				int co = cost(n, b, costs);
				if (co < mincost) {
					bestbase = vector<int>();
					bestbase.push_back(b);
					mincost = co;
				}
				else if (co == mincost) {
					bestbase.push_back(b);
				}
			}
			cout << "Cheapest base(s) for number ";
			cout << n << ":";
			for (int j = 0; j < bestbase.size(); j++) {
				cout << ' ' << bestbase[j];
			}
			cout << endl;
		}
	}




}


