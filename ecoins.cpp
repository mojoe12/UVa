#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int mincoins (const vector< pair<int, int> >& coins, vector<int>& arr, int emod, int c1, int c2) {
	cout << c1 << ' ' << c2 << endl;
	
	int dif = emod * emod - c1 * c1 - c2 * c2;
	
	if (dif < 0) return 1000000;
	if (dif == 0) return 0;
	
	int& arrval = arr[dif-1];
	if (arrval == -1) {
		int minnum = 1000000;
		for (int i = 0; i < coins.size(); i++) {
			int num = mincoins(coins, arr, emod, 
				c1 + coins[i].first, c2 + coins[i].second);
			minnum = min(minnum, num);
		}
		arrval = 1 + minnum;
	}
	return arrval;
}

int main() {
	int k;
	cin >> k;
	
	for (int c = 0; c < k; c++) {
		int n, emod;
		cin >> n >> emod;
		vector< pair<int, int> > coins (n);
		for (int i = 0; i < n; i++) {
			cin >> coins[i].first >> coins[i].second;
		}
		vector<int> arr (emod * emod, -1);
		
		int x = mincoins (coins, arr, emod, 0, 0);
		if (x >= 1000000) cout << "not possible\n";
		else cout << x << endl;
		
	}




}


