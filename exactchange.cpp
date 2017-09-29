#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

bool getmin(int price, const vector<int>& bills, int& mincost, int& mincoins, int i, int currcost, int currcoins) {
	
	if (currcost >= price) {
		if (currcost - price < mincost) {
			mincost = currcost - price;
			mincoins = currcoins;
		}
		if (currcost - price == mincost) {
			mincoins = min(mincoins, currcoins);
		}
		return false;
	}
	else if (i < bills.size()) {
		if (getmin(price, bills, mincost, mincoins, i+1, currcost + bills[i], currcoins + 1))
			getmin(price, bills, mincost, mincoins, i+1, currcost, currcoins);
	}
	return true;
}

int main() {
	int k;
	cin >> k;
	
	for (int c = 0; c < k; c++) {
		int price, n;
		cin >> price >> n;
		
		vector<int> bills (n);
		for (int i = 0; i < n; i++) {
			cin >> bills[i];
		}
		sort(bills.begin(), bills.end());
		
		int mincost = 10000, mincoins = 0;
		getmin(price, bills, mincost, mincoins, 0, 0, 0);
		cout << price + mincost << ' ' << mincoins << endl;
		
	}
}
